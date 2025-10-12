import unittest
from pathlib import Path

from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner


def main() -> None:
    suite = unittest.defaultTestLoader.discover("tests")
    results_file = Path("/autograder/results/results.json")

    with results_file.open("w") as f:
        JSONTestRunner(visibility="visible", stream=f).run(suite)


if __name__ == "__main__":
    main()

