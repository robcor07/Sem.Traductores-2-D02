#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExp>
#include <string>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList r;
    r<<"Lexema"<<"Simbolo"<<"Tipo"<<" "<<" "<<" ";

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(100);
    ui->tableWidget->setHorizontalHeaderLabels(r);
    ui->tableWidget->verticalHeader()->setVisible(false);


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit1->toPlainText();
    int flag=0,estado=0;
    QString lexema,simbolo,tipo;
    QString vec[100][3];
    int auxvec=0;

    for(int i=0;i<=text.length();i++)
    {
        if(flag==1)
        {
         i--;
         flag=0;
        }

        if(estado==0)
        {
            if(text[i]=="\n")//espacios
            {

                i++;
            }
            if(text[i]=="\n")//espacios
            {

                i++;
            }

            if(text[i].isSpace() or text[i]=="\n" or text[i]=="\f" or text[i]=="\r" or text[i]=="\t" or text[i]=="\v")//mas espacios
            {
                i++;

            }

            if(text[i]=="!" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opIgualdad";
                tipo="11";

            }
            if(text[i]=="!")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="opNot";
                tipo="10";

            }
            if(text[i]==">" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opRelac";
                tipo="7";

            }
            if(text[i]=="<" and text[i+1]=="=")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opRelac";
                tipo="7";

            }
            if(text[i]=="=")
            {
                estado=24;
                lexema+=text[i];
                simbolo="=";
                tipo="18";
                if(text[i+1]=="=")
                {
                    i++;
                    lexema+=text[i];
                    simbolo="opIgualdad";
                    tipo="11";

                }
            }
            if(text[i]=="<" or text[i]==">")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="opRelac";
                tipo="7";
            }
            if(text[i]=="*" or text[i]=="/")
            {
                estado=24;
                lexema+=text[i];
                simbolo="opMul";
                tipo="6";
            }
            if(text[i]=="+" or text[i]=="-")
            {
                estado=24;
                lexema+=text[i];
                simbolo="opSuma";
                tipo="5";
            }
            if(text[i]=="|" and text[i+1]=="|")
            {
                estado=24;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opOr";
                tipo="8";
            }
            if(text[i]=="&" and text[i+1]=="&")
            {
                estado=20;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                simbolo="opAnd";
                tipo="9";
            }
            if(text[i]==";")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=";";
                tipo="12";
            }
            if(text[i]==",")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=",";
                tipo="13";
            }
            if(text[i]=="(")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="(";
                tipo="14";
            }
            if(text[i]==")")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo=")";
                tipo="15";
            }
            if(text[i]=="{")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="{";
                tipo="16";
            }
            if(text[i]=="}")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="}";
                tipo="17";
            }
            if(text[i]=="$")
            {
                estado=24;
                lexema+=text[i];
                i++;
                simbolo="$";
                tipo="23";

            }
            if(text[i].isLetter())
            {
                estado=1;
                lexema+=text[i];
                simbolo="Identificador";
                tipo="0";
                i++;
            }
            if(text[i].isDigit() and text[i+1]==".")
            {
                estado=3;
                lexema+=text[i];
                i++;
                lexema+=text[i];
                i++;
                simbolo="real";
                tipo="2";

            }
            if(text[i].isDigit())
            {
                estado=2;


            }


        }
        if(estado==1)
        {
            while(text[i].isDigit() or text[i].isLetter() or text[i]=="_")
            {



                estado=1;
                lexema+=text[i];
                if(lexema=="if")
                {
                    tipo="19";
                    simbolo="if";

                    break;
                }
                if(lexema=="while")
                {
                    tipo="20";
                    simbolo="while";
                    i++;
                    break;
                }
                if(lexema=="return")
                {
                    tipo="21";
                    simbolo="return";
                    i++;

                    break;
                }
                if(lexema=="else")
                {
                    tipo="22";
                    simbolo="else";
                    i++;

                    break;
                }

                if(lexema=="int" or lexema=="char" or lexema=="float" or lexema=="void" )
                {
                    tipo="4";
                    simbolo="tipo";
                    i++;

                    break;
                }

                simbolo="identificador";
                tipo="0";
                i++;






            }



                flag=1;
                estado=24;

        }
        if(estado==2)
        {
            while(text[i].isDigit())
            {
                lexema+=text[i];
                simbolo="entero";
                tipo="1";

                i++;
            }
            flag=1;
            estado=24;

        }
        if(estado==3)
        {
            while(text[i].isDigit())
            {
                lexema+=text[i];
                simbolo="real";
                tipo="3";

                i++;
            }
            flag=1;
            estado=24;

        }
        if(estado==24)
        {
            estado=0;

        }
        vec[auxvec][0]=lexema;
        vec[auxvec][1]=simbolo;
        vec[auxvec][2]=tipo;

        ui->tableWidget->setItem(auxvec,0,new QTableWidgetItem(lexema));
        ui->tableWidget->setItem(auxvec,1,new QTableWidgetItem(simbolo));
        ui->tableWidget->setItem(auxvec,2,new QTableWidgetItem(tipo));
        auxvec+=1;
        estado=0;

        lexema="";
        simbolo="error";
        tipo="";



    }

}
