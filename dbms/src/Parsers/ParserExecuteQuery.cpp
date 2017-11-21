#include <Parsers/ParserExecuteQuery.h>

#include <Common/typeid_cast.h>
#include <Parsers/ASTIdentifier.h>
#include <Parsers/ExpressionElementParsers.h>
#include <Parsers/CommonParsers.h>
#include <Parsers/ASTExecuteQuery.h>


namespace DB
{
bool ParserExecuteQuery::parseImpl(Pos & pos, ASTPtr & node, Expected & expected)
{
    Pos begin = pos;

    ParserKeyword s_execute("EXECUTE");
    ParserIdentifier name_p;

    ASTPtr command;

    if (!s_execute.ignore(pos, expected))
        return false;

    if (!name_p.parse(pos, command, expected))
        return false;

    auto query = std::make_shared<ASTExecuteQuery>(StringRange(begin, pos));
    query->command = typeid_cast<ASTIdentifier &>(*command).name;
    node = query;

    return true;
}
}
