# itlinescoreboard
Библиотека для работы со светодиодными табло компании [it-line](http://it-line.info/).
### Информация

Библиотека написана по doxygen доку(находится в папке docs).
В папке src находятся два заголовочных файлы cpp, по которым и были сделаны большинство классов.
Основная логика - общение с табло происходит по UDP. Табло способны принимать правильно сформированные udp пакеты, адресованные им лично или отправленные broadcastom на всю сеть.
### Использование библиотеки

``` csharp
//создание объекта для отправки данных на табло(в конструктор передается порт для открытия сокета)
ScoreboardSender sender = new ScoreboardSender(5002);
//поиск табло возвращает словарь с табло(key - MAC)
var scoreboards = sender.FindScoreboards();
foreach (var scoreboard in scoreboards)
{
	Console.WriteLine($"Найдено табло:{scoreboard.Value}");
}
int brigthness = 100;
//пример установки яркости табло(практически везде можно передать target для установки, это mac).
//Если передать null запрос будет широковещательным на всю сеть/
sender.SetBrightness(brigthness, null);

//пример установки ячейки Nvstr(передается индекс ячейки в табло, выравнивание строки и сама строка) + target
sender.SetNvstrData(new StringMessage(0, StringProfile.StrCenter, "hello world"), null);

```