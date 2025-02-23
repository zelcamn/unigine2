#ifndef GAME_H
#define GAME_H

#include "QObject"

#include <QMetaType>

namespace gamens
{

    Q_NAMESPACE

    // Перечисление вариантов игры
    enum class Variants
    {
        Rock,
        Paper,
        Scissors
    };

    Q_ENUM_NS(Variants)

    // Класс "игры"
    class Game : public QObject
    {
        Q_OBJECT
    private:
        // Выбранный вариант и готовность к игре
        Variants chosenVariant = Variants::Rock;
        bool isReady = false;

        // Текст результата игры
        QString resultText = " ";

    public:
        Q_INVOKABLE void proceed_game(bool isEnemyReady, int enemyChoice);
        bool compare_variants(int enemyChoice);

        bool get_is_ready();
        void set_is_ready(bool isReady);

        Variants get_chosenVariant();
        void set_chosenVariant(Variants variant);

        QString get_resultText();
    };
}

Q_DECLARE_METATYPE(gamens::Variants)

#endif // GAME_H
