#include  <vector>
/*
 *
 * Лекция 7 апр 2022
 *
 * Шаблоны
 *
 * Позволяют избавиться  от написания  лишнего  кода когда функция работает 
 * с разными  типами
 * 
 * В Си такую проблему решали с помощью макросов.  
 * В Си++ добавили  шаблоны которые парадигма обобщенного программирования.
 * Шаблоны по сути инструкция компилятору чтобы создать (инстанцировать)
 * реализации шаблонных классов при нахождении вызовов соответственных функций
 *
 * При определении методов шаблонного класса надо их  помещать в тот же файл,
 * поскольку информация не передается. (Иначе, придется использовать явное
 * инстанцирование)
 * 
 * class и typename после стандарта C++17 взаимозаменяемы.
 * 
 * Если мы хотим использовать приведение типов, необходимо
 * явно указать тип, с которым работает функция и все будет хорошо,
 * например:
 *
 * template<class T>
 * foo(T, T){}
 *
 * int i;
 * double d;
 * foo<double>(i,d); // void foo (double a1, double a2)
 * foo(i,d);  // ошибка компиляции 
 * 
 * При  подстановке в T,
 * квалификатор const и ссылки отбрасываются,  т.к. они ни на что  не  влияют.
 * foo(int i)  = foo(const int ci) = foo(int &ri) = foo (const int &cri)
 *
 * foo(int i) !=  foo(int * a) != foo(const int * a)
 *
 * template<class T>
 * void foo (T *);
 * квалификатор const  сохраняется
 *
 * В  случае с 
 * template<class T>
 * void  foo(T&);
 * Такая же ситуация
 * И как следствие передать rvalue в таком случае не получится.
 *
 * В шаблонах T&& фактически не является rvalue ссылкой,
 * а является универсальной ссылкой.
 * (т.е. используется то, что требуется)
 * int i = 1;
 * const int ci=2;
 * int &ri =  i;
 * const int  &cri = i;
 *
 * foo(i); // void (foo(int &a)
 * foo(ci); // 
 * foo(i); //
 * foo(i); //
 * foo(100); // foo(int &&a);
 *  -  все будет  хорошо
 *
 *
 * Массивы:
 * для указателя понятно
 * если по  ссылке темплейт, то
 * void bar(int (&a)[5]);
 *
 *
 * Порядок применения
 * 1.) Нешаблонная функция с совпадающими типами параметров
 * 2.) Шаблонная функция
 * 3.) Нешаблонная функция с возможным приведением типов
 *
 *
 */

 // Функиця обертка
 template <typename T1,  typename T2>
 //void wrapper(T1&& a1, T2&& a2) { foo(a1,a2); } //  Так...? 
 void wrapper(T1&& a1, T2&& a2) { foo(std::forward<T1>(a1),std::forward<T2>(a2)); } //
/*
 *  std::forward - для передачи значений из универсальных ссылок
 *  и избегания лишних копирований
 *  опредлена в стандартной  библиотеке так
 */
 template <class T>
 T&&  forward(typename std::remove_reference<T>::type &t) noexcept {
 return static_cast<T&&>(t);
 }
/*
 * Если мы в него передадим ссылочный  тип, то форвард  тоже это  вернет
 * А если передадим эрвалю, то форвард вернет ссылку на рвалью
 * Сами ссылки на рвалью являются элвалью ссылками, т.е.
 */
int &&rr=9;
int Z&&rr2 = rr; //Ошибка компиляции,  т.к. rr - L-value
int &&rr3 = static_cast<int&&>(rr); // так можно
//Именно это имплементировано  стд форвард
/*
 * С форвардом-  перемещение - 
 * без него   - ненужное копирование
 *
 * Этот прием - 
 * Идеальная  передача, но чаще - perfect forwarding
 *
 */


/*
 * Шаблоны классов
 *
 * Пример - классы коллекции. (stl)
 *
 * При создании объекта необходимо явно указать аргументы шаблона
 * Stack<double> doubleStack; 
 * при этом компилятор  сам создает необходимые рализации класса в текущей
 * единице  трансляции (неянвое инстанцирование)
 *
 *
 * Тонкости:
 * 1 - Зависимые имена
 * В контейнере определен  iterator
 * template<class Container>
 * void  foo(const Container & data){
 *  typename  Container::iterator item =data.begin();
 * }
 *
 * 2 - Специализация шаблонов
 * Можно определить специальную версию шаблона, которая будет вызываться
 * с параметрами определнных типов (чтобы сделать эффективнее, например)
 *
 * template<>
 * void sortArray<MyClass>(MyClass *array,  size_t size) {
 *  ... более эффективная сортировка массива объектов
 * }
 * Бывают частичные специализации, позволяющие указывать только  часть
 * параметров
 * Очень полезно для классов
 * 
 *
 * 3 - Параметры-значения (non-type)
 * template <class  T, size_t N>
 * size_t getArrayLength(const T(&)[N]) {
 *      return N;
 * } 
 * // Соответственно. не работает для указателей (array to pointer decay)
 * // Ну и динамического массива тоже
 * Не для  всех типов, но например int, указатели
 *
 * 4 - Параметры шаблоны
 * template <class T, template<class> class Container>
 * class Foo {
 *  Container<T> container;
 * };
 *
 * Foo<double,Stack>  object;
 * До C++17 шаблонный параметр должен быть описан именно  со словом class,
 * а не typename (единственное отличие между ними)
 *
 * 5 - Параметры  по  умолчанию
 * template <class T,
 *           class Allocator = std::allocator<T>>
 *  class Vector {...};
 *
 * 6 - C++ 11 - Шаблоны с переменным  числом параметров - variatic templates
 * template<class  First,  class...  Other>
 * auto  sum(Firstfirst, Other... other) {
 *      return first + sum(other...);
 * }
 * class... Other пакет параметров шаблона
 * Other... Other пакет параметров функции
 * other... раскрытие пакета параметров
 *
 * std::make_uniqeu как  раз таки с помощью этого и сделан
 */
template<typename T, typename ... Args>
unique_ptr<T> make_unique(Args&&... args){
return unique_ptr<T>(new T(std::forward<Args>(args)...));  // Каждый параметр оборачиваетсяв forward
}
std::unique_ptr<Object> optr = std::make_unique<Object>(p1,p2);

/*
 * 7  -  C++ 11 - Шаблонные псевдонимы типов
 *
 *
 */
using Counter = unsigned long;
Counter counter = 0;
using Data = double[1000];
Data dataArray;

using IntVector = std::vector<int>;
IntVector vector;

template<typename T> using  Ptr = T  * ;
Ptr<int> ptr_int; // Указатель на int
/*
 *  Пару слов про контроль типов
 *  Контроль типов параметров  шаблона и возможных действий  с ними 
 *  происходит только при попытке компиляции. (Недостаток C++)
 *  
 *  Концепты (C++20)
 *  способы написания ограничений  для типов параметра шаблонов
 *  template<class T>
 *  concept Addable = requires (T a,  T  b) {
 *      a + b;
 *  };
 *
 *  // для значений Т должна  быть допустима операция сложения
 *  template<Addable T>
 *  void foo(T a1, T a2){
 *      ...
 *  }
 */
