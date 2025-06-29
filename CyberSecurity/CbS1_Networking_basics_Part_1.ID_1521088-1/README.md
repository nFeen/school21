# Основы сетей. Часть 1 — «Первый опыт»
Аннотация: Данный проект включает в себя разбор основ сетей, модели OSI / TCP/IP на примере работы в среде GNS3, а также изучение протоколов IP, ARP, ICMP.

---

>💡 Если это твой первый проект, заполни эту [форму](http://opros.so/kAnXy).

>💡 [Нажми сюда](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624), чтобы поделиться с нами обратной связью на этот проект. Это анонимно и поможет нашей команде сделать обучение лучше. Рекомендуем заполнить опрос сразу после выполнения проекта.

## Содержание
1. [Chapter I](#chapter-i) \
   1.1. [Рекомендации к проекту](#рекомендации-к-проекту)
2. [Chapter II](#chapter-ii) \
   2.1. [Компьютерная сеть](#компьютерная-сеть)
3. [Chapter III](#chapter-iii) \
   3.1. [Задание 1. Расчет адресов](#задание-1-расчет-адресов) \
   3.2. [Задание 2. Знакомство с GNS3](#задание-2-знакомство-с-gns3) \
   3.3. [Задание 3. Multicast-запросы](#задание-3-multicast-запросы) \
   3.4. [Задание 4. ARP](#задание-4-arp) 


### Введение

>Для Ульриха день не задался с самого утра: местные маги взорвали лабораторию, на прошлой тренировке он повредил плечо, которое теперь мешало ему спать. В придачу к этому ментор заставил его разобрать беспорядок в древних рунах, о которых Ульрих только слышал от старшекурсников.
>
>Молодой охотник на монстров оделся, взял свой меч и быстрым шагом побежал в столовую на завтрак. Ученики называли ее «Терем» из-за того, что местные повара обращались к студентам «сударь» и «сударыня». После завтрака уже в приподнятом настроении Ульрих зашел в угловой кабинет, который все считали пустующим. На столе лежала груда камней с нацарапанными знаками, как бы намекая, что сегодня ему не посчастливится поспать в своей кровати.


## Chapter I
### Рекомендации к проекту
Как учиться в «Школе 21»:  
- На протяжении всего курса ты будешь самостоятельно добывать информацию. Пользуйся всеми доступными средствами поиска информации, к примеру, Google и GigaChat. Будь внимателен к источникам информации: проверяй, думай, анализируй, сравнивай. 
- Взаимообучение (P2P, Peer-to-Peer) — это процесс, при котором учащиеся обмениваются знаниями и опытом, выступая одновременно в роли учителей и учеников. Этот подход позволяет учиться не только у преподавателя, но и друг у друга, что способствует более глубокому пониманию материала.
- Не стесняйся просить помощи: вокруг тебя такие же пиры, которые тоже проходят этот путь впервые. Не бойся откликаться на просьбы о помощи. Твой опыт ценен и полезен, смело делись им с другими участниками. 
- Не списывай, а если пользуешься помощью — всегда разбирайся до конца, почему, как и зачем. Иначе твое обучение не будет иметь никакого смысла. 
- Если ты на чем-то застрял, и кажется, что ты уже все перепробовал, но все равно непонятно, куда идти, — просто передохни! Поверь, этот совет помогал многим экспертам по КБ в их работе. Проветрись, перезагрузи голову и, возможно, в следующий раз тебе наконец придет нужное решение!
- Важен не только результат обучения, но и сам процесс. Нужно не просто решить задачу, а понять, КАК ее решить.
- На пути к мастерству в сфере кибербезопасности ты получаешь возможность быть частью поддерживающего и вдохновляющего сообщества Школы 21 по Кибербезопасности. Присоединяйся в [RocketChat](https://rocketchat-student.21-school.ru/channel/cybersec_21),чтобы получать свежие анонсы от сообщества, а так же вступай в [Telegram](https://t.me/+r5wufz8L3mUzOGUy) для коммуникации. 

Как работать с проектом: 
- Перед выполнением проект необходимо склонировать с GitLab в одноименный репозиторий.
- Все файлы с кодом необходимо создавать в папке `src` склонированного репозитория.
- После клонирования проекта необходимо создать ветку `develop` и вести разработку в ней. После этого пушить в GitLab также нужно ветку `develop`.
- В твоей директории не должно быть иных файлов, кроме тех, что обозначены в заданиях. 

Дисклеймер: 
- В целях геймификации обучения проект подается в формате истории, чтобы у тебя была возможность отвлечься от сложных заданий и тонны теории в Гугле. Если придуманная история кажется тебе бесталанной и скучной, можно указать на это в обратной связи, чтобы автор поплакал над своим писательским навыком. Также можно пропускать введение в каждом задании и фокусироваться только на содержательной части.

## Chapter II
### Компьютерная сеть 
Компьютерная (вычислительная) сеть — совокупность устройств и систем, которые логически или физически связаны друг с другом и взаимодействуют. К сетевым устройствам относятся серверы, компьютеры, телефоны и пр. Размерность таких сетей может быть разной — от домашней сети из двух-трех устройств до сети предприятия или всего интернета. Сети — объемная тема, и начинать выполнение заданий этого проекта рекомендуется с самостоятельного изучения основной теории по каждому из них (в данном проекте нам нужны будут как минимум знания по первым четырем уровням модели OSI), после чего уже приступать к лабораторной работе.

Лучший вариант для ознакомления с основами сетей — пособия по подготовке к сдаче Cisco CCNA, т. к. информация в них отлично структурирована и покрывает все основные необходимые темы. При знании на достаточном уровне английского языка рекомендую для изучения теории использовать прочтение CCNA в видеоформате (например, можно обратить внимание на cbt nuggets или аналоги). Можно работать и с печатной/электронной версией пособия по подготовке к сдаче Cisco CCNA. 

_Примечание_: переведенное пособие на русский язык по подготовке к сдаче CCNA категорически не рекомендуется ввиду наличия ошибок и неточностей перевода.

Дополнительно можно обратить внимание на хабр-блог [«Сети для самых маленьких»](https://habr.com/ru/articles/447080/). Для продолжения изучения материалов по теме сетей и их безопасности после прохождения данного курса рекомендую обратить внимание на следующие материалы: 
* Implementing and Operating Cisco Security Core Technologies;
* Cisco Enterprise Network Core Technologies.

## Chapter III
### Задание 1. Расчет адресов
Для решения данного задания нужны знания в следующих темах: IP-адреса, бинарная система счисления, деление сети на подсети, маска сети.

>Для начала Ульрих решил пересчитать руны. Какая ошибка! Бедняга не знал, что руны считаются в двоичной системе счисления. Он начал откладывать по одной руне в сторону и считать их вслух. Ульрих осознал подвох после того, как отложил 2 руны, а насчитал уже 10. Чтобы разложить камни по горсткам, придется пользоваться новой для себя системой счисления...

IP (internet protocol) — протокол сетевого уровня. Да-да, именно по нему вычисляли еще 10 лет назад любого хулигана в сети. Однако основная его задача — реализовать передачу трафика между разными IP-сетями. Происходит это благодаря IP-адресам. Эти адреса подобны твоему адресу прописки. Причем аналогия абсолютно прямая: в рамках всей планеты абсолютно одинаковых адресов не бывает, однако в нескольких разных городах могут быть одинаковые номера домов, улиц и квартир (например, г. Москва, ул. Советская, д. 12 или г. Питер, ул. Советская, д. 12).

Статья по теме: https://habr.com/ru/articles/134892/.

Для закрепления понимания того, что такое CIDR-нотация и сетевая адресация, тебе необходимо решить несколько практических заданий, приведённых ниже:

1. Рассчитать бинарную нотацию для адресов:
    * 178.101.89.7
    * 201.57.153.161
2. Представь, что тебе нужно выделить подсети под различные сегменты организации N — технологический (3 машины), серверный (16 машин) и пользовательский (из 32 машин).
3. Сети с какими масками необходимо выделить для каждого из сегментов? Приведи обоснование своего ответа.

Решение заданий и обоснование запиши в текстовый файл с именем `ip-1`.

### Задание 2. Знакомство с GNS3
Для решения данного задания нужны знания в следующих темах: GNS3, импортирование Cisco образа в GNS3. 

**Важно**: при выполнении заданий не забывай сохранять конфигурации устройств.

>Всю боль разочарования Ульрих познал после того, как разложил все руны по кучкам, но не подготовил для них хранилища. Хотя он и не помнил точных указаний со стороны ментора, было очевидно, что камни должны быть отсортированы и аккуратно сложены в какие-то емкости. Красивых полок и шкафов в кабинете не было. Сначала это его расстроило, но потом он понял, что ментор специально не подготовил для него емкостей, чтобы научить юного студента мыслить неординарно. Поэтому Ульрих решил эмулировать полки и шкафы с помощью мешков из-под волшебных грибов.

Для подготовки виртуальной среды, в которой ты будешь выполнять лабораторные работы по этому и следующим трем блокам, тебе необходимо настроить и подготовить тестовую среду GNS3 и изучить принципы работы в ней. GNS3 — это виртуальная среда, которая, по аналогии с виртуальными машинами, позволяет тебе эмулировать работу сетевого оборудования. Для подготовки виртуальной среды GNS3 нужно выполнить ее установку (если она не была предварительно выполнена), создание проекта и импорт образов Cisco IOS.

Образы Cisco IOS скачай по этой ссылке, IOS 3745: https://blog.netskills.ru/2011/12/ios-gns3-ios-for-gns3.html.
 
Статья по теме: https://docs.gns3.com/docs/getting-started/your-first-gns3-topology.
 
После установки задай права для dumpcap:
```
sudo chmod +x /usr/bin/dumpcap
```
 
В случае затруднений тебе помогут следующие ссылки:
- Github GNS3: https://github.com/GNS3/gns3-gui.

**Важно**: не устанавливай GNS как службу systemd, т. к. при такой инсталляции в некоторых версиях есть баг с созданием проекта. 

Инструкции по установке: https://docs.gns3.com/docs/getting-started/installation/linux.

В качестве ответа загрузи в репозиторий проект в GNS3, на котором размещено импортированное устройство Cisco 3745.

### Задание 3. Multicast-запросы
Для решения данного задания нужны знания в следующих темах: broadcast, multicast, ICMP, Wireshark.

>Когда все руны были разложены по мешкам, осталось дело за малым: перенести сотни килограммов камней в подвал, чтобы кабинет внезапно не превратился в склад. К сожалению, ноющее плечо не позволило поднять Ульриху даже одного мешка.
>«Дело дрянь, — подумал Ульрих и сказал себе вслед за этим: — Придется звать на помощь».
>
>Чтобы его услышали проходящие мимо кабинета студенты, несостоявшийся грузчик закричал во все горло, обращаясь сразу ко всем: «Помогите! Кто-нибудь!»


Broadcast — широковещательный адрес, используемый для передачи трафика всем узлам в сети (реализован как на L2, так и на L3). Это своего рода крик в громкоговоритель, который услышат только те, кто находятся с тобой в одной сети. Для этого «крика» в каждой сети всегда отводится отдельный адрес, как правило, самый последний (например, для сети 192.168.1.0/24 это 192.168.1.255).

Multicast — адрес, используемый для передачи трафика к группе узлов в сети. По сути, урезанный вариант broadcast.

ICMP — Internet Control Message Protocol, протокол, используемый для передачи информации об ошибках при передаче трафика. Популярным способом проверки сетевой доступности является ping — это команда, которая присутствует в каждой операционной системе и позволяет отправить ICMP echo запросы. Они в себе не содержат никакой полезной информации, это своего рода «тычок пальцем» в устройство.
 
Статья по теме: https://habr.com/ru/articles/217585/.

Твоя задача: 
- Создай проект.
- Добавь на него два сетевых устройства (используй образ Cisco 3745), соедини их, настрой их сетевые интерфейсы. 
- Запусти эмуляцию и собери пакетную трассу, обратившись на multicast IP-адрес по ICMP.
- С помощью Wireshark изучи результирующий файл пакетной трассы, обратив внимание на поля, отражающие информацию по L2, L3 и ICMP.
- Ответь на вопрос: на какой destination MAC-адрес отправляется ICMP-запрос? Ответ запиши в текстовый файл с именем `multicast`.
- Сохрани результирующий файл собранной пакетной трассы в файл с расширением .pcap с именем `multicast`.

В качестве итогового ответа выложи в репозиторий файл `multicast.pcap` и текстовый файл `multicast` с ответом на вопрос.

_Подсказка_: для того чтобы устройство отвечало на обращения по multicast-адресу, необходимо добавить интерфейс в multicast-группу. 

При возникновении сложностей в работе можешь использовать этот Help: https://docs.gns3.com/docs/getting-started/your-first-cisco-topology.

**Советы**:
* Не назначай сетевым интерфейсам «сложных» IP-адресов, лучше используй простые, например, 10.10.10.0/24. \
* В интерфейсе командной строки введи «?» для вывода справки. \
* Для завершения ввода команды используй клавишу TAB.
 
Дополнительно после выполнения этого задания рекомендуем самостоятельно изучить, что такое Broadcast Storm.

### Задание 4. ARP
Для решения данного задания нужны знания в следующих темах: ARP, 2 уровень модели OSI, Wireshark, GNS3.

>Помощь прибыла не сразу. Зато какая! Очаровательная девушка заглянула в кабинет и вопросительно посмотрела на Ульриха. Затем на мешки с камнями. Затем снова на Ульриха. В ее глазах мелькнуло сначала разочарование, потом любопытство, гнев и наконец желание сбежать. Но альтруизм возобладал. Вдвоем они управились за несколько часов, перенеся все мешки в подвал. Осталось разложить каждый мешок в конкретную ячейку с определенным номером, чтобы в дальнейшем их было легче искать.


ARP — address resolution protocol, позволяет определить MAC-адрес на основании известного IP-адреса. У каждого устройства есть ARP-таблица, которая является «дневником» — там записаны IP-адреса с привязанными к ним MAC-адресами.
 
Статья по теме: https://habr.com/ru/articles/138043/.
 
Продолжаем осваивать базовые сетевые протоколы на примере ARP. Разберем его также в формате анализа трафика между двумя сетевыми узлами в нашем проекте GNS3.

Твое задание:
- Запусти сбор пакетной трассы, выполни с одного из узлов команду ping до IP соседнего устройства. Убедись, что после этого в ARP таблице присутствует соответствующая ARP-запись.
- В Wireshark ознакомься с содержимым ARP- и ICMP-пакетов.
- На какой MAC адрес в первом ARP пакете отправляется запрос? Как называется данный адрес? Ответы запиши в текстовый файл с именем `arp`. 
- Обрати внимание, от какого MAC-адреса исходит ответный пакет. Сохрани результирующий файл .pcap Wireshark с именем `arp`.

Итого загрузи в репозиторий три файла: проект `gns3`, файл `arp.pcap` и текстовый файл `arp`.
 
Дополнительно при выполнении этого задания рекомендуем самостоятельно изучить, что такое Gratuitous ARP.

