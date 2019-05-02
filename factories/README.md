
# Target factories

All your build targets should be created via a factory here, see comments in the *.cmake file for more info.

* For executables and libraries: [executables_and_libs.cmake](executable_and_lib.cmake)
* For unit test (executables): [utest.cmake](utest.cmake)

The following files are used by the factories.

Helper function to remove symbols from built binary [settings/strip_symbols.cmake](settings/strip_symbols.cmake).
Compiler flags and additional features are configured in [settings/flags.cmake](settings/flags.cmake).