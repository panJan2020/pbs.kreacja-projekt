#include "mylabelfilter.h"
#include "mainwindow.h"
#include <QLabel> // Potrzebne do obsługi QLabel i metody setText

MyLabelFilter::MyLabelFilter(QObject *parent) : QObject(parent)
{
}

bool MyLabelFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QString nazwaPrzyciskowa = "Nieznany";

        // Odczytujemy aktualne współrzędne kliknięcia na obiekcie
        int x = mouseEvent->pos().x();
        int y = mouseEvent->pos().y();

        switch (mouseEvent->button()) {
        case Qt::LeftButton:
            nazwaPrzyciskowa = "Lewy";
            mam_lewyklawisz = true;

            // PODPUNKT D: Emitowanie sygnału po kliknięciu lewym przyciskiem myszy
            emit klikniecieMyszki(x, y);
            break;

        case Qt::MiddleButton:
            nazwaPrzyciskowa = "Środkowy";
            break;
        case Qt::RightButton:
            nazwaPrzyciskowa = "Prawy";
            break;
        default:
            break;
        }

        QString komunikat = QString("Mysz klawisz (%1)").arg(nazwaPrzyciskowa);
        MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
        if (mainWindow) {
            mainWindow->setInfo(komunikat, 1);
        }
        return false;
    }

    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QLabel *label = qobject_cast<QLabel*>(watched);
        if (label) {
            label->setText(QString("Pozycja kursora: [%1 : %2]").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));
        }
        return false;
    }

    if (event->type() == QEvent::MouseButtonRelease) { //
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        // Przechwytujemy puszczenie konkretnie LEWEGO klawisza myszy
        if (mouseEvent->button() == Qt::LeftButton) { //
            mam_lewyklawisz = false; // Zerujemy flagę

            // Wyświetlamy komunikat statusowy w oknie głównym
            MainWindow *mainWindow = qobject_cast<MainWindow*>(parent());
            if (mainWindow) {
                mainWindow->setInfo("lewy klawisz puszczony", 3); //
            }
        }
        return false; // Pozwalamy widgetowi label na domyślną reakcję
    }

    return QObject::eventFilter(watched, event);
}