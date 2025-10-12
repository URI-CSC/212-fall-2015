import shutil
import subprocess
import unittest
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Optional, Sequence

from gradescope_utils.autograder_utils.decorators import weight


@dataclass
class CommandOutput:
    stdout: str
    stderr: str
    exit_code: int
    timeout: bool


def run(cmd: Iterable[Any], timeout: Optional[int] = 5) -> CommandOutput:
    cmd = " ".join(str(x) for x in cmd)
    try:
        proc = subprocess.run(
            cmd, shell=True, capture_output=True, text=True, timeout=timeout
        )
        return CommandOutput(
            stdout=proc.stdout,
            stderr=proc.stderr,
            exit_code=proc.returncode,
            timeout=False,
        )
    except subprocess.TimeoutExpired:
        return CommandOutput(stdout="", stderr="", exit_code=-1, timeout=True)


def build(cpp_paths: Sequence[Path], executable_path: Path) -> CommandOutput:
    gcc_flags = [
        "-std=c++17",
        "-g",
        "-O0",
        "-Wall",
        "-Wextra",
        "-Wpedantic",
        "-fsanitize=address,undefined",
        "-fstack-protector-strong",
        "-D_GLIBCXX_DEBUG",
    ]
    cmd = ["g++", *gcc_flags, "-o", executable_path.as_posix(), *(cpp_path.as_posix() for cpp_path in cpp_paths)]
    return run(cmd, timeout=None)


class AutograderBase(unittest.TestCase):

    def setUp(self) -> None:
        self.autograder_path = Path("/autograder/source")
        self.submission_path = Path("/autograder/submission")
        shutil.copytree(
            self.autograder_path / "submission",
            self.submission_path,
            dirs_exist_ok=True,
        )

    def assert_cpp_tests(self, cpp_files: Sequence[str], executable_name: str) -> None:
        self.assert_exists(cpp_files)

        cpp_paths = [self.submission_path / cpp_file for cpp_file in cpp_files]
        executable_path = self.submission_path / executable_name

        output = build(cpp_paths, executable_path)

        if output.timeout:
            self.fail(
                "\n".join(
                    [
                        "",
                        "ERROR".center(80, "*"),
                        f"\nTime limit exceeded when compiling {cpp_files}",
                    ]
                )
            )

        if output.exit_code != 0:
            self.fail(
                "\n".join(
                    [
                        "",
                        "ERROR".center(80, "*"),
                        f"Compilation of {cpp_files} failed with exit code {output.exit_code}",
                        "STDOUT".center(80, "*"),
                        output.stdout,
                        "STDERR".center(80, "*"),
                        output.stderr,
                    ]
                )
            )

        output = run([executable_path.absolute().as_posix()])

        if output.timeout:
            self.fail(
                "\n".join(
                    [
                        "",
                        "ERROR".center(80, "*"),
                        f"\nTime limit exceeded when running {executable_name}",
                    ]
                )
            )

        if output.exit_code != 0:
            self.fail(
                "\n".join(
                    [
                        "",
                        "ERROR".center(80, "*"),
                        f"Running {executable_name} failed with exit code {output.exit_code}",
                        "STDOUT".center(80, "*"),
                        output.stdout,
                        "STDERR".center(80, "*"),
                        output.stderr,
                    ]
                )
            )

    def assert_analysis_tests(self, file: str) -> None:
        self.assert_exists([file])
        path = self.submission_path / file
        if "TODO" in path.read_text():
            self.fail(
                "\n".join(
                    [
                        "",
                        "ERROR".center(80, "*"),
                        f"\n Analysis {file} is not complete [contains TODO]",
                    ]
                )
            )

    def assert_exists(self, files: Sequence[str]) -> None:
        for file in files:
            path = self.submission_path / file
            if not path.exists():
                self.fail(
                    "\n".join(
                        [
                            "",
                            "ERROR".center(80, "*"),
                            f"\nFile {file} does not exist",
                        ]
                    )
                )
