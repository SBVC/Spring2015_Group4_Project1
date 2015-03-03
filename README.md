# Whiteboard

Whiteboard is an interactive program designed for keeping track of a selection of students and their scores.

# Setting up Unit Tests

1. UnitTest++ folder contains project files for Code::Blocks and Visual Studio. For other IDEs, I direct you to [this wiki article](http://wiki.codeblocks.org/index.php?title=UnitTesting) for setting up UnitTest++ in Code::Blocks. The same basic ideas should apply to other IDEs.
2. UnitTests contains a Code::Blocks project. For other IDEs, you need to specify to use the library "libUnitTest++.a" (in UnitTest++\Deliv\Release) in the linker, as well as specify to include the src directory and UnitTest++/src directory for includes.

For the program itself, just include everything in the src directory into your IDE, and it should be fine.
