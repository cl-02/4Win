if(EXISTS "/Users/clemenshanselmann/Desktop/4Gewinnt/DummyCppCmakeRepo-main/cmake-build-debug/dummy_test[1]_tests.cmake")
  include("/Users/clemenshanselmann/Desktop/4Gewinnt/DummyCppCmakeRepo-main/cmake-build-debug/dummy_test[1]_tests.cmake")
else()
  add_test(dummy_test_NOT_BUILT dummy_test_NOT_BUILT)
endif()
