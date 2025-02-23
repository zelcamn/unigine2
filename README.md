# Камень ножницы бумага
Данное приложение - это игра "камень, ножницы, бумага", разработанное с использованием фреймворка Qt версии 6.8.2 и имеющее (по идее) локальный мультиплеер.

## Сборка и запуск приложения

Для сборки игры нужен установленный фреймворк Qt. Сборка выполняется с использованием следующих команд, находясь 
в созданной заранее папке ```build``` в корневой папке проекта:
1. ``` cmake .. ```
2. ``` cmake --build . ```

После выполнения данных команд создастся исполняемый файл игры. На компьютере, где будет запускаться данный файл, также должен быть установлен Qt.

Если при вызове первой команды появится ошибка об отсутствии cmake файлов для Qt, добавить к команде следующий параметр: ```-DCMAKE_PREFIX_PATH=Путь/К/Вашим/Qt/Библиотекам/cmake/Qt6```.
## Скриншоты
![image](https://github.com/user-attachments/assets/3607cfdc-8d8a-49ad-9bfe-3cca5752c7d7)

## Основные решения
1. Игра реализована в отдельном классе ```Game```. Случай, когда оба игрока выбрали один и тот же вариант, считается проигрышным для них обоих.
2. Для работы с сетью использовался модуль QtNetwork. Создан отдельный класс ```Connector```, реализующий "Peer-to-Peer" соединение, который обрабатывает входящие данные и отправляет исходящие. Чтобы подключится к другому игроку нужно ввести порт и IP-адрес, на котором работает его сервер в игре.
