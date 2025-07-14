# Qt SIGNAL 함수

## 목차

1. [QTcpSocket](#1-qtcpsocket-주요-시그널-함수-설명)

## 1. QTcpSocket 주요 시그널 함수 설명

### ⦁ connected()

소켓이 서버에 **성공적으로 연결되었을 때** 자동으로 발생하는 시그널.
connectToHost() 함수 호출 후, 서버와 TCP 핸드셰이크가 성공적으로 완료되면 이 시그널이 발생. 
이 시그널이 발생했다는 것은 이제 클라이언트가 서버와 데이터를 주고받을 준비가 된 상태임을 의미. 
보통 이 시그널에 연결된슬롯에서는 연결 성공을 알리는 UI 업데이트나 초기 데이터 전송 등의 작업을 수행.
- **예시**:
  ```cpp
  connect(pQTcpSocket, SIGNAL(connected()), this, SLOT(socketConnectServerSlot()));
  ```

---

### ⦁ disconnected()

소켓 연결이 끊어졌을 때 발생하는 시그널. 
연결 종료는클라이언트가 스스로 disconnectFromServer()를 호출했거나, 서버 측에서 연결을닫았거나, 네트워크 문제(케이블 분리, 서버 다운 등)로 인해 발생할 수 있다. 
이 시그널을 처리하는 슬롯에서는 주로 자원을 정리하거나, 연결이 끊겼음을 사용자에게 알리거나, 재연결을 시도하는 로직을 구현한다.
- **예시**:
  ```cpp
  connect(pQTcpSocket, SIGNAL(disconnected()), this, SLOT(socketClosedServerSlot()));
  ```

---

### ⦁ readyRead()

- 소켓으로부터 **읽을 수 있는 데이터가 도착했을 때(새로운 데이터를 수신하여 소켓의 내부 읽기 버퍼에 데이터가 쌓였을 때)** 발생하는 시그널.
즉, read()나 readAll() 같은 함수를 호출하여 데이터를 읽을 수 있는 상태가 되었음을 알려준다. 
중요한 점은 이 시그널이 한 번의 데이터 전송에 여러 번 발생할 수도 있고, 여러 개의 작은 데이터 패킷이 도착했을 때 한 번만 발생할 수도 있다는 것이다. 
따라서 데이터를 수신할 때 완전한 형태의 메시지가 도착했는지 확인하는 파싱 로직을 잘 구현해야 한다.

- **예시**:
  ```cpp
  connect(pQTcpSocket, SIGNAL(readyRead()), this, SLOT(socketReadDataSlot()));
  ```

---

### ⦁ errorOccurred(QAbstractSocket::SocketError)

- 네트워크 작업 중 소켓 관련 **오류가 발생했을 때** 발생하는 시그널.
QAbstractSocket::SocketError 열거형 값을 인자로 전달받아 어떤 종류의 에러가 발생했는지 상세히 알 수 있다. 
예를 들어, ConnectionRefusedError (서버가 연결을 거부), HostNotFoundError (호스트를 찾을 수 없음), NetworkError(네트워크 장애) 등이 있다. 
이 시그널을 통해 네트워크 오류에 대한 예외처리를 정교하게 수행할 수 있다.
- **예시**:
  ```cpp
  connect(pQTcpSocket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(socketErrorSlot()));
  ```

---

### ⦁ 참고: New Signal-Slot Syntax (Qt5 이상)

```cpp
connect(pQTcpSocket, &QTcpSocket::connected, this, &MyClass::socketConnectServerSlot);
connect(pQTcpSocket, &QTcpSocket::disconnected, this, &MyClass::socketClosedServerSlot);
connect(pQTcpSocket, &QTcpSocket::readyRead, this, &MyClass::socketReadDataSlot);
connect(pQTcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),
        this, &MyClass::socketErrorSlot);
```

---

## 2. QTimer
QTimer는 Qt에서 일정 시간 간격으로 특정 작업을 반복하거나, 지정된 시간이 지난 
후에 한 번만 작업을 실행하고 싶을 때 사용하는 핵심 클래스이다. 
GUI 프로그래밍에서 화면을 주기적으로 갱신하거나, 네트워크 상태를 확인하는 등 다양한 용도로 사용된다.

QTimer는 별도의 스레드에서 동작하는 것이 아니라, Qt의 이벤트 루프(Event Loop)에 의해 관리된다. 
이 덕분에 GUI 스레드를 막지 않으면서(non-blocking) 타이머 기능을 사용할 수 있다.

### ⦁ timeout() 시그널
timeout()은 QTimer의 가장 중요한 시그널로, 이 시그널은 `QTimer`에 설정된 시간 간격(interval)이 만료될 때마다 발생한다.
쉽게 말해, QTimer를 "알람 시계"라고 생각한다면 timeout()은 "알람이 울리는 것"과 같다.

- 작동 방식
  1. `QTimer` 객체 생성: 먼저 QTimer의 인스턴스를 만든다.
  2. 시간 간격 설정: setInterval(int msec) 함수를 사용해 timeout() 시그널이 발생할 주기를 밀리초(ms) 단위로 설정한다. 
  예를 들어 setInterval(1000)은 1초마다 시그널이 발생하도록 설정한다.
  3. 시그널과 슬롯 연결: connect() 함수를 사용하여 timeout() 시그널이 발생했을 때 실행할 함수(슬롯)를 연결한다.
  4. 타이머 시작: start() 함수를 호출하여 타이머를 시작한다.
  5. 실행: 타이머가 시작되면, Qt의 이벤트 루프는 설정된 시간 간격마다 timeout() 시그널을 발생시키고, 연결된 슬롯 함수가 자동으로 호출된다.

## 3. QButton