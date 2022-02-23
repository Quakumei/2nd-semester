#include "../src/Stack.hpp"
#include "../src/Queue.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Stack contains data as intended", "[Stack]"){
    Stack<int> stack;

    // Undeflow excpetion expected.
    REQUIRE_THROWS_AS(stack.drop(), std::logic_error);
    REQUIRE(stack.isEmpty());

    stack.push(5);
    stack.push(2);
    stack.push(57);
    stack.push(10);
    stack.push(7);
    stack.push(8);
    stack.push(22);
    INFO("The stack is " << stack.print());    REQUIRE(stack.drop() == 22);
    REQUIRE(stack.drop() == 8);
    REQUIRE(stack.drop() == 7);
    REQUIRE(stack.drop() == 10);
    stack.push(89);
    stack.push(15);
    REQUIRE(stack.drop() == 15);
    REQUIRE(stack.drop() == 89);
    REQUIRE(stack.drop() == 57);    
}

TEST_CASE("Queue contains data as intended"){
    Queue<int> queue;

    // добавляем в очередь элементы
    REQUIRE(queue.isEmpty());
    queue.push(8);
    queue.push(15);
    queue.push(16);
    queue.push(100);
    queue.push(-8);

    // выводим
    INFO("The queue is " << queue.print());

    // проверяем метод drop, должно вернуться число, помещённое в очередь первым
    REQUIRE(queue.drop() == 8);

    // ещё раз выводим
    INFO("The queue after first taking is " << queue.print());


    Queue<int> queue2 = queue;	// здесь вызывается конструктор копирования (эквивалентно Queue queue2(queue);)

    // извлекаем ещё один элемент из исходной очереди
    REQUIRE(queue.drop()==15);

    // и выводим, чтобы показать, что очереди разные
    INFO("After second taking from first queue:\n" << "queue: " << queue.print() << "\nqueue2: " << queue2.print());
    REQUIRE(queue2.drop()==15);
    REQUIRE(queue2.drop()==16);
    
    queue2 = queue;	// а вот здесь уже вызывается оператор присваивания
    REQUIRE((queue.drop()==16 && queue2.drop()==16));
    
    // извлекаем оставшиеся элементы и "лишний"
    REQUIRE(queue.drop()==100);
    REQUIRE(queue.drop()==-8);
    REQUIRE_THROWS_AS(queue.drop(), std::logic_error);
}
        



