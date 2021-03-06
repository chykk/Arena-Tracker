#include "graphicsitemsender.h"
#include "cardgraphicsitem.h"


GraphicsItemSender::GraphicsItemSender(QObject *parent, Ui::Extended *ui) : QObject(parent)
{
    this->ui = ui;
    this->lastCode = "";
}


void GraphicsItemSender::sendPlanCardEntered(QString code, QPoint rectCardTopLeft, QPoint rectCardBottomRight)
{
    if(code == lastCode)    return;

    lastCode = code;
    rectCardTopLeft = ui->planGraphicsView->mapFromScene(rectCardTopLeft);
    rectCardTopLeft = ui->planGraphicsView->mapToGlobal(rectCardTopLeft);
    rectCardBottomRight = ui->planGraphicsView->mapFromScene(rectCardBottomRight);
    rectCardBottomRight = ui->planGraphicsView->mapToGlobal(rectCardBottomRight);

    QPoint planViewTopLeft = ui->planGraphicsView->mapToGlobal(QPoint(0,0));
    int planViewBottom = ui->planGraphicsView->mapToGlobal(QPoint(0,ui->planGraphicsView->height())).y();

    QRect rect(planViewTopLeft.x(), rectCardTopLeft.y(), ui->planGraphicsView->width(), rectCardBottomRight.y()-rectCardTopLeft.y());
    emit cardEntered(code, rect, planViewTopLeft.y(), planViewBottom);
}


void GraphicsItemSender::sendPlanCardLeave()
{
    lastCode = "";
    emit cardLeave();
}


void GraphicsItemSender::sendResetDeadProbs()
{
    emit resetDeadProbs();
}


void GraphicsItemSender::sendCheckBomb(QString code)
{
    emit checkBomb(code);
}


void GraphicsItemSender::sendHeroTotalAttackChange(bool friendly, int totalAttack, int totalMaxAttack)
{
    emit heroTotalAttackChange(friendly, totalAttack, totalMaxAttack);
}
