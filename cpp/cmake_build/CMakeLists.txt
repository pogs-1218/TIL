cmake_minimum_required(VERSION 3.10)

project(foo)

set(abc "") # clear

function(scope_2)
  message("Scope 2 (before): '${abc}'")
  set(abc "786" PARENT_SCOPE)
  message("Scope 2 (after): '${abc}'")
endfunction()


function(foo)
  message("in foo: abc = '${abc}'")
  unset(abc)
  message("in foo unset: abc = '${abc}'")
endfunction()

function(boo)
  message("in boo: abc = '${abc}'")
  set(abc "789")
  message("modified in boo: abc = '${abc}'")
  foo()
endfunction()

# message("rv (before): ${abc}")
# message("cv (before): ${xyz}")

set(abc "123")

boo()

message("main boo: abc = '${abc}'")
# set(xyz "321" CACHE STRING "")

# message("rv (after): ${abc}")
# message("cv (after): ${xyz}")

add_subdirectory(boo)

# message("after boo: ${abc}")

add_executable(foo foo.cc)
