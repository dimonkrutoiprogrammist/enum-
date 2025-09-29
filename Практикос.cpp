
/*
 Пользователь вводит с клавиатуры символ. Определить,
какой это символ: Буква, цифра, знак препинания или другое
*/

/*
#include <iostream>

using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    char ch; // Вводим переменную с типом чар, чтобы ввести символы
	cout << "Введите символ для определнния - ";
	cin >> ch;
    int code = (int)ch;  //ASCII-код символа

    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)) {
        cout << "Это буква" << endl; //Проверка через ASCII является ли это буквой
    }
    else if (code >= 48 && code <= 57) {
        cout << "Это цифра" << endl; //Проверка через ASCII является ли это цифрой
    }
    else if ((code >= 33 && code <= 47) || (code >= 58 && code <= 64) ||
        (code >= 91 && code <= 96) || (code >= 123 && code <= 126)) {
        cout << "Это знак препинания" << endl; //Проверка через ASCII является ли это знаком препинания
    }
    else {
        cout << "Другой символ" << endl;
    }

    return 0;
}

*/


/*
Написать программу подсчета стоимости разговора для
разных мобильных операторов.Пользователь вводит дли
тельность разговора и выбирает с какого на какой оператор
он звонит.Вывести стоимость на экран.
*/

/* #include <iostream>
using namespace std;

enum Operator {
    MTS = 1,      // 1
    MEGAFON = 2,  // 2
    TELE2 = 3     // 3
};

int main() {
    setlocale(LC_ALL, "ru");

    int minute;
    int from, to;

    cout << "Введите длительность в минутах - ";
    cin >> minute;

    cout << "Выберите оператор, с которого звоните:\n1 - MTS\n2 - Megafon\n3 - Tele2\n";
    cin >> from;

    cout << "Выберите оператор, на который звоните:\n1 - MTS\n2 - Megafon\n3 - Tele2\n";
    cin >> to;

    int itog = 0;

    if (from == MTS && to == MEGAFON) itog = 44;
    else if (from == MTS && to == TELE2) itog = 51;
    else if (from == MEGAFON && to == MTS) itog = 31;
    else if (from == MEGAFON && to == TELE2) itog = 51;
    else if (from == TELE2 && to == MTS) itog = 51;
    else if (from == TELE2 && to == MEGAFON) itog = 31;
    else {
        cout << "Звонок с " << from << " на " << to << " разговор бесплатный." << endl;
        return 0;
    }
    int total = itog * minute;

    cout << "Стоимость разговора: " << total << " руб." << endl;

    return 0;
}

*/


/*
Вася работает программистом и получает 50$ за каждые
100 строк кода. За каждое третье опоздание на работу Васю
штрафуют на 20$. Реализовать меню:
 ■ пользователь вводит желаемый доход Васи и количество
 опозданий, посчитать, сколько строк кода ему надо написать;
 ■ пользователь вводит количество строк кода, написанное
 Васей и желаемый объем зарплаты. Посчитать, сколько
 раз Вася может опоздать;
 1
Неделя 5
 ■ пользователь вводит количество строк кода и количество
 опозданий, определить, сколько денег заплатят Васе и
 заплатят ли вообще
*/


#include <iostream>
using namespace std;

// Возможные действия в меню
enum Option {
    RASSCHITAT_STROKI = 1,  // Узнать, сколько строк кода нужно написать
    RASSCHITAT_OPTSDANIYA,  // Узнать, сколько раз можно опоздать
    RASSCHITAT_ZARPLATU     // Узнать, сколько заплатят
};

int main() {
    setlocale(LC_ALL, "ru");

    // Показываем пользователю, что он может выбрать
    cout << "Выберите действие:\n";
    cout << "1 - Узнать, сколько строк кода нужно написать \n";
    cout << "2 - Узнать, сколько раз можно опоздать \n";
    cout << "3 - Узнать, сколько заплатят \n";
    cout << "Введите номер - ";

    int vibor;
    cin >> vibor;

    // если выбрал 1
    if (vibor == RASSCHITAT_STROKI) {
        int zhelaemaya_zarplata, kolichestvo_optsdanii;
        cout << "Введите желаемый доход - ";
        cin >> zhelaemaya_zarplata;
        cout << "Введите количество опозданий - ";
        cin >> kolichestvo_optsdanii;

        // Считаем штрафы 
        int shtraf = (kolichestvo_optsdanii / 3) * 20;
        // Сколько нужно заработать 
        int nuzhno_zarabotat = zhelaemaya_zarplata + shtraf;
        // сколько строк нужно написать
        int nuzhno_strok = (nuzhno_zarabotat / 50) * 100;

        cout << "Нужно написать " << nuzhno_strok << " строк кода.\n";
    }
    // выбор 2
    else if (vibor == RASSCHITAT_OPTSDANIYA) {
        int kolichestvo_strok, zhelaemaya_zarplata;
        cout << "Введите количество строк кода - ";
        cin >> kolichestvo_strok;
        cout << "Введите желаемый доход - ";
        cin >> zhelaemaya_zarplata;

        // Сколько вася заработает за строки
        int zarabotok = (kolichestvo_strok / 100) * 50;
        // потеря на штрафак
        int raznitsa = zarabotok - zhelaemaya_zarplata;
        // Сколько штрафов можно
        int vozmozhnie_shtrafi = raznitsa / 20;
        // Сколько раз можно опоздать 
        int razreshennie_optsdaniya = vozmozhnie_shtrafi * 3;

        cout << "Можно опоздать " << razreshennie_optsdaniya << " раз\n";
    }
    // Если выбрал 3
    else if (vibor == RASSCHITAT_ZARPLATU) {
        int kolichestvo_strok, kolichestvo_optsdanii;
        cout << "Введите количество строк кода - ";
        cin >> kolichestvo_strok;
        cout << "Введите количество опозданий - ";
        cin >> kolichestvo_optsdanii;

        // Сколько заработал
        int zarabotok = (kolichestvo_strok / 100) * 50;
        // Сколько штрафов
        int shtraf = (kolichestvo_optsdanii / 3) * 20;

        // итог зп 
        int itogovaya_zarplata = zarabotok - shtraf;

        // не заплатят если штрафы больше зп
        if (itogovaya_zarplata < 0) itogovaya_zarplata = 0;

        cout << "Васе заплатят - " << itogovaya_zarplata << "$\n";
    }
    // неккоректный ввод
    else {
        cout << "Неверный выбор.\n";
    }

    return 0;
}