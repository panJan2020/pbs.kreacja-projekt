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

    // B: Wykrywanie zdarzenia naciśnięcia klawisza na klawiaturze
    if (event->type() == QEvent::KeyPress)
    {
        // B: Konwersja ogólnego zdarzenia do formatu zdarzenia klawiatury
        QKeyEvent *zdarzenie_klawiatury = static_cast<QKeyEvent*>(event);

        // B: Odczytanie aktualnego położenia kursora myszy na ekranie (współrzędne globalne)
        QPoint punkt = kursor_myszki.pos();
        int xx = punkt.x();
        int yy = punkt.y();

        // B: Instrukcja wyboru reagująca na konkretne klawisze strzałek
        switch(zdarzenie_klawiatury->key())
        {
        case Qt::Key_Up:
            ui->label_2->setText("STRZAŁKA GORA");
            yy -= 5; // B: Przesunięcie kursora w górę o 5 pikseli
            break;
        case Qt::Key_Down:
            ui->label_2->setText("STRZAŁKA DOL");
            yy += 5; // B: Przesunięcie kursora w dół o 5 pikseli
            break;
        case Qt::Key_Left:
            ui->label_2->setText("STRZAŁKA LEWO");
            xx -= 5; // B: Przesunięcie kursora w lewo o 5 pikseli
            break;
        case Qt::Key_Right:
            ui->label_2->setText("STRZAŁKA PRAWO");
            xx += 5; // B: Przesunięcie kursora w prawo o 5 pikseli
            break;
        default:
            ui->label_2->setText(zdarzenie_klawiatury->text());
            break;
        }

        // B: Programowe ustawienie nowej globalnej pozycji kursora myszy na ekranie
        kursor_myszki.setPos(xx, yy);

        return true; // B: Zakończenie dalszego przetwarzania zdarzenia klawisza
    }

    return QObject::eventFilter(watched, event);
}