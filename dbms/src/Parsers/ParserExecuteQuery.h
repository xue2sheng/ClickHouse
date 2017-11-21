#pragma once

#include <Parsers/IParserBase.h>


namespace DB
{

/** Query USE db
  */
class ParserExecuteQuery : public IParserBase
{
protected:
    const char * getName() const { return "Execute query"; }
    bool parseImpl(Pos & pos, ASTPtr & node, Expected & expected);
};

}
