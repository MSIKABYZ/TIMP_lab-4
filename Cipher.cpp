/**
* @file Cipher.h
* @author Кадыкова В.В.
* @date 01.06.19
* @brief Шифрование методом маршрутной перестановки
*/
#pragma once
#include <string>
#include <stdexcept>
using namespace std;
/** @brief Шифрование методом vмаршрутной перестановки
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы
encrypt и decrypt.
* @warning Реализация только для английского языка
*/
class Cipher
{
	int n; ///< ключ, количество стлобцов
	/**
	* @brief Валидация текста
	* @param [in] s Строка для шифрования или расшифровывания
	* @return Валидная строка
	* @throw Error текст пустой, содержит недопустимые символы
	или ее длина короче ключа
	*/
	string getValidText(const string& s);
public:
	/**
	* @brief Конструктор по умолчанию
	* @details Запрещен
	*/
	Cipher() = delete;
	/**
	* @brief Конструктор для установки ключа
	* @param [in] key Целочисленный ключ
	* @throw Error ключ вырожденный
	*/
	Cipher(int key);
	/**
	* @brief Зашифровывание
	* @details По ключу строит таблицу. Заполняет текстом слева
	направо, сверху вниз.
	* Считывает - сверху вниз, справа налево.
	* @param [in] open_text Открытый текст. Не должен быть пустой
	строкой и короче значения ключа.
	* @return Зашифрованная строка
	* @throw Error текст пустой, содержит недопустимые символы
	или ее длина короче ключа
	*/
	string encrypt(const string& open_text);
	/**
	* @brief Расшифровывание
	* @details По ключу строит таблицу. Заполняет текстом сверху
	вниз, справа налево.
	* Считывает - слева направо, сверху вниз.
	* @param [in] open_text Открытый текст. Не должен быть пустой
	строкой и короче значения ключа.
	* @return Расшифрованная строка
	* @throw Error текст пустой, содержит недопустимые символы
	или ее длина короче ключа
	*/
	string decrypt(const string& cipher_text);
};
/**@brief Класс-исключение.
* @details Призводный от класса invalid_argument.
* При перегрузке конструкторов явно указаны вызов конструктора
базового класса с параметром.
*/
class Error:
	public invalid_argument
{
public:
	explicit Error (const string&
	                what_arg):invalid_argument(what_arg) {}
	explicit Error (const char*
	                what_arg):invalid_argument(what_arg) {}
};
