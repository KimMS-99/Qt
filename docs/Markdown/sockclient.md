# `SockClient` 클래스 (`sockclient.h`, `sockclient.cpp`)

`SockClient` 클래스는 TCP/IP 소켓 통신을 통해 [서버(라즈베리파이)](https://github.com/KimMS-99/C_CPP/blob/main/Tcp%3AIp/iot_server/iot_server.c)와 데이터를 주고받는 클라이언트 역할을 담당합니다. 이 클래스는 서버 연결, 데이터 송수신, 연결 상태 관리 등의 기능을 제공합니다.

## 주요 기능 및 역할

-   **서버 연결**: `connectToServerSlot`을 통해 지정된 IP 주소와 포트 번호로 서버에 연결을 시도합니다.
-   **데이터 송수신**: 서버로부터 데이터를 수신(`socketReadDataSlot`)하고, 서버로 데이터를 전송(`socketWriteDataSlot`)합니다.
-   **연결 상태 관리**: 서버 연결 성공(`socketConnectServerSlot`), 연결 종료(`socketClosedServerSlot`), 소켓 오류 발생(`socketErrorSlot`) 등의 이벤트를 처리합니다.

## 멤버 변수

-   `QTcpSocket *pQTcpSocket`: TCP 소켓 통신을 위한 객체 포인터.
-   `QString SERVERIP`: 연결할 서버의 IP 주소 (기본값: "192.168.0.89").
-   `int SERVERPORT`: 연결할 서버의 포트 번호 (기본값: 5000).
-   `QString LOGID`: 서버에 전송할 로그인 ID (기본값: "KMS_QT").
-   `QString LOGPW`: 서버에 전송할 로그인 비밀번호 (기본값: "PASSWD").
-   `BLOCK_SIZE`: 데이터 수신 시 버퍼 크기 (1024 바이트).

## 슬롯 (Slots)

-   `connectToServerSlot(bool &bFlag)`:
    -   서버 연결을 시도하는 슬롯.
    -   사용자로부터 서버 IP 주소를 입력받아 연결하거나, 입력이 없을 경우 기본 IP로 연결합니다.
-   `socketReadDataSlot()`:
    -   서버로부터 데이터가 수신되었을 때 호출되는 슬롯.
    -   수신된 데이터를 읽어 `socketRevcDataSig` 시그널을 통해 외부에 전달함.
-   `socketErrorSlot()`:
    -   소켓 통신 중 오류가 발생했을 때 호출되는 슬롯.
-   `socketConnectServerSlot()`:
    -   서버에 성공적으로 연결되었을 때 호출되는 슬롯.
    -   정의된 `LOGID`와 `LOGPW`를 서버로 전송합니다.
-   `socketClosedServerSlot()`:
    -   서버와의 연결이 끊겼을 때 호출되는 슬롯.
    -   소켓 연결을 닫습니다.
-   `socketWriteDataSlot(QString strData)`:
    -   지정된 문자열 `strData`를 서버로 전송하는 슬롯.

## 시그널 (Signals)

-   `socketRevcDataSig(QString)`:
    -   서버로부터 데이터를 성공적으로 수신했을 때 발생하는 시그널.
    -   수신된 문자열 데이터를 인자로 전달합니다.

## 라즈베리파이 서버 코드

이 클라이언트와 연동되는 라즈베리파이 서버 코드는 다음 GitHub 링크에서 확인할 수 있습니다:

[라즈베리파이 서버 코드 GitHub 링크](https://github.com/KimMS-99/C_CPP/blob/main/Tcp%3AIp/iot_server/iot_server.c)
