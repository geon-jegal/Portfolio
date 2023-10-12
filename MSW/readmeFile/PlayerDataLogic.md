PlayerDataLogic(2023-10-12 20:20)

  **PlayerDataLogic에 대한 내용을 기술한 readme파일입니다.**
  기본적으로 KeyConfigLogic와 동일한 형태로 작동합니다.
  SetData(), SaveData()가 클라이언트에서 실행되고 나머지는 전부 서버에서 실행된다.

  - EnterUserData
	- 게임에 입장한 유저의 id를 받아 데이터를 들고 온다. 

  - getData
	- 문자열로 입력받은 데이터를 테이블로 변환한다

  - SetData
	- 유저의 특정 데이터를 저장할 때 사용하는 함수
	- 만약 유저가 level up을 한다면 level, 스텟등을 저장하는데 사용한다
	- ex) _PlayerDataLogic:SetData("MaxExp", self.MaxExp)

  - SaveData
	- 테이블을 문자열로 변환 후 서버로 보낸다.

  - SendServer
	- 문자열로 변환한 데이터를 서버로 보낸다.

  - SetPlayer
	- 게임 입장 시 바로 실행하는 함수이다.
	- 유저의 데이터를 설정한다.

  - OnBeginPlay
	- 유저의 기초데이터를 설정한다.