from autograder_base import AutograderBase


class TestAll(AutograderBase):
	def test_mergesort(self) -> None:
		requirements = ['mergesort.cpp']
		dependencies = ['mergesort.h', 'test_mergesort.cpp', 'doctest.h']
		executable_name = 'test_mergesort'
		cpp_files = ['mergesort.cpp', 'test_mergesort.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_mergesort_analysis(self) -> None:
		analysis = 'mergesort.md'
		self.test_mergesort()
		self.assert_analysis_tests(analysis)

	def test_quicksort(self) -> None:
		requirements = ['quicksort.cpp']
		dependencies = ['quicksort.h', 'test_quicksort.cpp', 'doctest.h']
		executable_name = 'test_quicksort'
		cpp_files = ['quicksort.cpp', 'test_quicksort.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_quicksort_analysis(self) -> None:
		analysis = 'quicksort.md'
		self.test_quicksort()
		self.assert_analysis_tests(analysis)

	def test_customsort(self) -> None:
		requirements = ['customsort.cpp']
		dependencies = ['customsort.h', 'test_customsort.cpp', 'doctest.h']
		executable_name = 'test_customsort'
		cpp_files = ['customsort.cpp', 'test_customsort.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)

	def test_customsort_analysis(self) -> None:
		analysis = 'customsort.md'
		self.test_customsort()
		self.assert_analysis_tests(analysis)

	def test_quicksort_median_pivot(self) -> None:
		requirements = ['quicksort_median_pivot.cpp']
		dependencies = ['quicksort_median_pivot.h', 'test_quicksort_median_pivot.cpp', 'doctest.h']
		executable_name = 'test_quicksort_median_pivot'
		cpp_files = ['quicksort_median_pivot.cpp', 'test_quicksort_median_pivot.cpp']
		self.assert_exists(requirements)
		self.assert_exists(dependencies)
		self.assert_cpp_tests(cpp_files, executable_name)
