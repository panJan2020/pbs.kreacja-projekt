#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);

    info.setMinimumWidth(250);
    info.setFrameStyle(QFrame::WinPanel);
    setInfo("Yupi... Czy ten tekst będzie widać?", 1);

    czas_info.setMinimumWidth(150);
    czas_info.setFrameStyle(QFrame::Raised | QFrame::Box);
    czas_info.setAlignment(Qt::AlignCenter);
    czas_info.setText(czas.currentTime().toString("HH:mm:ss"));

    pasek.setMinimumWidth(150);
    pasek.setRange(0,59);
    pasek.setValue(0);

    ui->statusBar->addPermanentWidget(&czas_info);
    ui->statusBar->addPermanentWidget(&pasek);
    ui->statusBar->addPermanentWidget(&info);

    zegarek = new QTimer (this);
    zegarek->start(1000);           // interwał w [ms]
    connect(zegarek,SIGNAL(timeout()),this,SLOT(on_timeout()));

    setInfo(QString("<center>Yupii... Komunikat na start aplikacji ;-)"),10);

    ui->label->setMinimumSize(QSize(800,600));
    ui->label->setToolTip(QString("<center>Tu będziemy bazgrolić\n i \nWyświetlać obrazki</center>"));
    // piksele_obrazu = QPixmap(800,600);
    // piksele_obrazu.fill(Qt::white);
    // ui->label->setPixmap(piksele_obrazu);

    setMinimumSize(QSize(1024,768));
    qApp->installEventFilter(this);

    // Tworzymy obiekt filtra, przekazując 'this' (MainWindow) jako rodzica
    filtrLabela = new MyLabelFilter(this);
    // Instalujemy filtr lokalnie na obiekcie ui->label
    ui->label->installEventFilter(filtrLabela);

    // PODPUNKT E: Połączenie sygnału z filtra z nowym slotem w MainWindow
    connect(filtrLabela, SIGNAL(klikniecieMyszki(int,int)),
            this, SLOT(mamKlikniecieMyszki(int,int)));

    mam_shift = false;

    ui->label->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    zegarek->stop();
    delete zegarek;

    delete ui;
}

void MainWindow::setInfo(QString tekst, int ile)
{
    if (!info.text().isEmpty()) return;
    info.setText(tekst);
    licznik=ile;
}

void MainWindow::on_timeout()
{
    // klasyczny mechanizm programowania dekrementacyjnego licznika ważności informacji
    if (licznik!=0) if (--licznik==0) info.clear();

    // aktualizuj pole czasu w pasku statusowym
    czas_info.setText(czas.currentTime().toString("HH:mm:ss"));

    // aktualizuj pasek postępu w pasku statusowym
    pasek.setValue(czas.currentTime().toString("ss").toInt());
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        int kodKlawisza = keyEvent->key();
        QString opisSpecjalny = "";

        switch (kodKlawisza) {
        case Qt::Key_Left:
            opisSpecjalny = "strzałka Lewo";
            break;
        case Qt::Key_Right:
            opisSpecjalny = "strzałka Prawo";
            break;
        case Qt::Key_Up:
            opisSpecjalny = "strzałka Góra";
            break;
        case Qt::Key_Down:
            opisSpecjalny = "strzałka Dół";
            break;
        case Qt::Key_PageUp:
            opisSpecjalny = "Klawisz PageUp";
            break;
        case Qt::Key_PageDown:
            opisSpecjalny = "klawisz PageDown";
            break;
        case Qt::Key_Space:
            opisSpecjalny = "klawisz Spacja";
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            opisSpecjalny = "klawisz Enter";
            break;
        case Qt::Key_Shift:
            opisSpecjalny = "klawisz Shift";
            mam_shift = true;
            break;
        default:
            break;
        }

        QString komunikat;
        if (!opisSpecjalny.isEmpty()) {
            komunikat = "klawisz specjalny: " + opisSpecjalny;
        } else {
            if (mam_shift) {
                komunikat = "klawisz: \"" + keyEvent->text() + "\" [z shiftem]";
            } else {
                komunikat = "klawisz: \"" + keyEvent->text() + "\"";
            }
        }

        setInfo(komunikat, 2);

        return false;
    }

    if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if (keyEvent->key() == Qt::Key_Shift) {
            mam_shift = false;
            //setInfo("klawisz SHIFT puszczony", 1);
        }

        return false;
    }

    return QMainWindow::eventFilter(obj, event);
}

// PODPUNKT E: Implementacja funkcji slotu obsługującej kliknięcie
void MainWindow::mamKlikniecieMyszki(int x, int y)
{
    // Formatowanie tekstu ze współrzędnymi kliknięcia
    QString wiadomosc = QString("kliknięcie myszki na współrzędnych [%1:%2]").arg(x).arg(y);

    // Wyświetlenie komunikatu w pasku statusu przy użyciu Twojej metody setInfo (na 10 sekund)
    setInfo(wiadomosc, 10);
}

void MainWindow::on_action_Koniec_triggered()
{
    QMessageBox oknoWyjscia (QMessageBox::Warning,   // ogólny typ okienka
                "Wyjście z Programu",                // Tekst w belce tytułowej
                "Czy chcesz wyjść z Programu ?",     // Tekst na półtnie okienka
                QMessageBox::Yes | QMessageBox::No); // jakie klawisze mają się pojawić

    oknoWyjscia.setButtonText(QMessageBox::Yes,"Tak");   // spolszczenie klawiszy
    oknoWyjscia.setButtonText(QMessageBox::No,"Nie");

    QPoint srodek = geometry().center();
    oknoWyjscia.move(srodek.x()-150,srodek.y()-100);

    if (oknoWyjscia.exec()==QMessageBox::Yes)        // jeśli klient wybierze Tak
    {
        QApplication::quit();                        // zamknięcie aplikacji
    }
    else
    {
        /* nic nie rób */
    }
}

void MainWindow::on_actionO_Prog_ramie_triggered()
{
    QPoint srodek = geometry().center();
    int x= oknoAbout.width()/2;
    int y= oknoAbout.height()/2;

    oknoAbout.move(srodek.x()-x,srodek.y()-y);
    oknoAbout.show();
    setInfo(QString("Wybrano opcję: O Programie"),10);
}

void MainWindow::on_action_Otw_rz_triggered()
{
    QString wybrany_plik = QFileDialog::getOpenFileName(this,   // kto wywołał
                         tr("Otwórz Plik graficzny"),           // tekst w belce
                         "",                                    // katalog otwarcia
                         tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)")); // filtry

    QMessageBox Informacja(QMessageBox::Information,
                           "Błąd wyboru pliku",
                           "Nie wybrano pliku do otwarcia",
                           QMessageBox::Ok);

    if (wybrany_plik.isEmpty())     // klient wybrał Cancel
    {
        QPoint srodek = geometry().center();
        Informacja.move(srodek.x()-150,srodek.y()-100);
        Informacja.exec();
    }
    else                                // klient wskazał właściwy plik graficzny
    {
        nazwa_pliku = wybrany_plik;     // zapamiętujemy nazwę pliku
        plik_obrazka = new QImage();
        plik_obrazka->load(nazwa_pliku);

        piksele_obrazu = QPixmap::fromImage(*plik_obrazka);
        // są metody do konwersji IMAGE<->PIXMAP w obie strony !!!
        // Image na Pixmap -> robimy fromImage
        // Pixmap na Image -> robimy toImage

        ui->label->setPixmap(piksele_obrazu);

        delete plik_obrazka;    // kasujemy zmienną bo już jej nie potrzebujemy
    }
}

void MainWindow::on_actionZapi_sz_triggered()
{
    QString wybrany_plik = QFileDialog::getSaveFileName(this,   // kto wywołał
                         tr("Zapis Pliku graficznego"),           // tekst w belce
                         "",                                    // katalog otwarcia
                         tr("JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)")); // filtry

    QMessageBox Informacja(QMessageBox::Information,
                           "Błąd wyboru pliku",
                           "Nie wybrano pliku do zapisu",
                           QMessageBox::Ok);

    if (wybrany_plik.isEmpty())
    {
        QPoint srodek = geometry().center();
        Informacja.move(srodek.x()-150,srodek.y()-100);
        Informacja.exec();
    }
    else
    {
        if (piksele_obrazu.isNull())
        {
            // mamy błąd niezainicjowanej zmiennej
        }
        else
        {
            QImage plik_do_zapisu = piksele_obrazu.toImage();
            if (plik_do_zapisu.size().isValid()==true)
                plik_do_zapisu.save(wybrany_plik);
        }
    }
}
