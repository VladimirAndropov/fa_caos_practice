# Мессенджер на сокетах

---

Проект свободен: нет

Участники: Анохов Влад, Курбанова Комила, Шевердов Никита

Предложен студентами: да

Ссылка на репозиторий: https://github.com/komilakurbanova/SocketMessenger

---

**Задача**

Написать мессенджер, который будет работать через сокеты. Поддерживать серверную часть и клиентскую с интерфейсом.


**Функционал**

### Со стороны юзера:

- мессенджер с приятным GUI, возможность смотреть/открывать чаты, писать  туда, смотреть историю чата
- Админский доступ, чтобы была возможность банить пользователей / другие админские штучки
- Возможность присылать стикеры (забиндить на спецсимволы типа ‘/1‘ ASCII картиночки)

### С нашей стороны:

Клиент-серверное приложение

### Задачи для клиент-серверного приложения:

- Придумать протокол передачи данных (придумать, как ужать данные настолько, чтобы отправлять сообщения могли только люди, состоящие в чатах, при этом быстро)
- Один и тот же сокет может отправлять и принимать данные, поэтому проблем с общением клиент-сервер быть не должно. User каждый момент времени (раз в 4 секунды, например) будет отправлять серверу запрос, чтобы обновить данные (сделать многопоточно или асинхронно будет самым лучшим решением)
- Авторизация пользователей
- Шифрование данных
- Хранение данных в базах данных (PostgreSQL например)
- Возможность создавать личные чаты
- Ввести закрытые и открытые аккаунты - с людьми с открытыми аккаунтами можешь начать чат, введя ник, с закрытыми можно начать чат, только если знаешь его id
- Сделать функцию просмотра открытых аккаунтов
- Хранить последние n сообщений + все последние непросмотренные сообщения
- Когда мы перестаём просить обновления (вышли из чата), все данные начинают копиться как непросмотренные
- Сообщением считается всё до первого ‘\n’ или какого-то флага, отвечающего за конец