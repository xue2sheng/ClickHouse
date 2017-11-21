#include <Parsers/ASTExecuteQuery.h>
#include <Interpreters/Context.h>
#include <Interpreters/InterpreterExecuteQuery.h>
#include <Common/typeid_cast.h>


namespace DB
{

BlockIO InterpreterExecuteQuery::execute()
{
    const String & new_command = typeid_cast<const ASTExecuteQuery &>(*query_ptr).command;
    context.getSessionContext().setCurrentCommand(new_command);
    return {};
}

}
