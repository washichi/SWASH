#include "swashuiadmin.h"
#include "swashuicustomer.h"
#include "communication.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SwashUIAdmin uia;
    SwashUICustomer uic;

    Communication customer("192.168.146.143", 5001);
    Communication administartor("192.168.146.143", 5001);

    uia.setup(&administartor, "5001");
    uic.setup(&uia, &customer, "5001");
    
    uia.show();
    uic.show();

    return a.exec();
}
