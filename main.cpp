#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


using namespace std;
int main(int argc, char *argv[])
{
    vector <pair <double , double > > ball;
    vector < pair <double , double> > left;
    vector < pair <double , double> > right;
    QChar space(' ');
    string s;
    QFile file("/home/arminsadreddin/Documents/posLogExtractor/input.txt");
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return 0;
    }
    QTextStream in(&file);
    QString myText = in.readAll();


    for(int f=1;f<311;f++){
        string show1 = "show ";
        string show2 = "show ";
        QString str1;
        QString str2;
        str1.setNum(f);
        str2.setNum(f+1);
        show1.append(str1.toStdString());
        show2.append(str2.toStdString());


        int index_num1 = myText.indexOf(QString::fromStdString(show1) , 0);
        int index_num2 = myText.indexOf(QString::fromStdString(show2) , 0);

        //cout << index_num1 << " - "<<index_num2 << "\n";
        //return 0;


        QString current_cycle_log = myText.mid(index_num1 , index_num2 - index_num1);
//        cout << current_cycle_log.toStdString()<<endl;
        //return 0;


        int index_l[12];
        int index_r[12];


        int index_ball_data = current_cycle_log.indexOf("b");


//        index_l[1] = current_cycle_log.indexOf("l 1");
//        index_l[2] = current_cycle_log.indexOf("l 2");
//        index_l[3] = current_cycle_log.indexOf("l 3");
//        index_l[4] = current_cycle_log.indexOf("l 4");
//        index_l[5] = current_cycle_log.indexOf("l 5");
//        index_l[6] = current_cycle_log.indexOf("l 6");
//        index_l[7] = current_cycle_log.indexOf("l 7");
//        index_l[8] = current_cycle_log.indexOf("l 8");
//        index_l[9] = current_cycle_log.indexOf("l 9");
//        index_l[10] = current_cycle_log.indexOf("l 10");
//        index_l[11] = current_cycle_log.indexOf("l 11");

//        for(int i=1;i<12;i++){

//            cout << index_l[i]<<endl;

//        }

        for(int i=1;i<12;i++){
            QString l(QString::fromStdString("l "));
            l.append(QString::number(i));
            //l.append(")");
            //cout << l.toStdString() << endl;
            index_l[i] = current_cycle_log.indexOf(l);
        }

        for(int i=1;i<12;i++){
            QString r(QString::fromStdString("r "));
            r.append(QString::number(i));
            //r.append(")");
            index_r[i] = current_cycle_log.indexOf(r);
        }

        bool isSecondSpace = false;
        bool record = false;
        QString ball_x;
        QString ball_y;
        int i ;
        //cout << index_ball_data << endl;
        for(i= index_ball_data ; isSecondSpace == false ; i++){

            if(current_cycle_log[i] == QChar(' ')){
                if(record){
                    isSecondSpace = true;
                    continue;
                }
                record = true;
                continue;
            }


            if(record){
                ball_x.append(current_cycle_log.at(i));
            }


        }

        for(;current_cycle_log.at(i) != space;i++){
            ball_y.append(current_cycle_log.at(i));
        }


        //cout << f << " : " << ball_x.toStdString() << " - "<<ball_y.toStdString() << "\n";
        pair <double , double> temp;
        temp.first = ball_x.toDouble();
        temp.second = ball_y.toDouble();
        ball.push_back(temp);
        //ball.push_back(pair<double,double>(ball_x.toDouble(),ball_y.toDouble()));

        isSecondSpace = false;
        record = false;

        QString l_x;
        QString l_y;
        for(int j=1;j<12;j++){
            //cout << "index_l = " << index_l[j] << endl;
        for(i= index_l[j] ; isSecondSpace == false ; i++){

            if(current_cycle_log[i] == QChar(' ')){
                if(record){
                    isSecondSpace = true;
                    continue;
                }
                record = true;
                continue;
            }


            if(record){
                l_x.append(current_cycle_log.at(i));
            }


        }

        for(;current_cycle_log.at(i) != space;i++){
            l_y.append(current_cycle_log.at(i));
        }


        pair <double , double> temp;

        temp.first = l_x.toDouble();
        temp.second = l_y.toDouble();
        left.push_back(temp);


        }




        isSecondSpace = false;
        record = false;

        QString r_x;
        QString r_y;

        for(int j=1;j<12;j++){
            //cout << "index_l = " << index_r[j] << endl;
        for(i= index_r[j] ; isSecondSpace == false ; i++){

            if(current_cycle_log[i] == QChar(' ')){
                if(record){
                    isSecondSpace = true;
                    continue;
                }
                record = true;
                continue;
            }


            if(record){
                r_x.append(current_cycle_log.at(i));
            }


        }

        for(;current_cycle_log.at(i) != space;i++){
            r_y.append(current_cycle_log.at(i));
        }


        pair <double , double> temp;

        temp.first = r_x.toDouble();
        temp.second = r_y.toDouble();
        right.push_back(temp);


        }



        cout << ball.at(0).first << " - " << ball.at(0).second << endl;
        for(int l=1;l<12;l++){
            cout << left.at(l).first << " - "<< left.at(l).second << endl;
        }
        for(int r=1;r<12;r++){
            cout << right.at(r).first << " - "<< right.at(r).second << endl;
        }




    }



    file.close();

}
