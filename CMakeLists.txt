cmake_minimum_required(VERSION 3.13)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project1 main.cpp Lexer.cpp Lexer.h Parser.cpp Parser.h Command.h openDataServerCommand.h conectCommand.h Expression.h defineVarCommand.h PrintCommand.h ConditionParser.h whileCommand.h ifCommand.h PlacementCommand.h main.h Var.h SleepCommand.h CommandExperssion.h SymbolTable.h Calculator.h)