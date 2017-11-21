#pragma once

#include <Parsers/IAST.h>


namespace DB
{


/** USE query
  */
class ASTExecuteQuery : public IAST
{
public:
    String command;

    ASTExecuteQuery() = default;
    ASTExecuteQuery(const StringRange range_) : IAST(range_) {}

    /** Get the text that identifies this element. */
    String getID() const override { return "ExecuteQuery_" + command; }

    ASTPtr clone() const override { return std::make_shared<ASTExecuteQuery>(*this); }

protected:
    void formatImpl(const FormatSettings & settings, FormatState & state, FormatStateStacked frame) const override
    {
        settings.ostr << (settings.hilite ? hilite_keyword : "") << "EXECUTE " << (settings.hilite ? hilite_none : "") << backQuoteIfNeed(command);
        return;
    }
};

}
