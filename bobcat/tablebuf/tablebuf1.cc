#include "tablebuf.ih"

TableBuf::TableBuf(TableSupport &tableSupport, size_t nColumns, 
            FillDirection direction, WidthType widthType)
: 
    TableBase(tableSupport, nColumns, direction, widthType)
{}

