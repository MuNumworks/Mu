#include "list_book_controller.h"

namespace readertest 
{
View* ListBookController::view()
{
    return &m_tableView;
}

int ListBookController::numberOfRows() const
{
    return 0;
}   

KDCoordinate ListBookController::cellHeight()
{
    return 50;
}

HighlightCell * ListBookController::reusableCell(int index)
{
    return nullptr;
}
    
int ListBookController::reusableCellCount() const
{
    return 0;
}

ListBookController::ListBookController(Responder * parentResponder):
    ViewController(parentResponder),
    m_tableView(this, this)
{
}

}