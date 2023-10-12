 # KeyConfig(2023-05-24 17:00)

**KeySetting관련 컴포넌트, 로직, 스크립트, 데이터셋에 관련된 readme파일입니다.**   

    1. KeyConfigLogic
         - 유저 입장 시 해당 유저의 커스텀 키 세팅이 있는지 확인
         - 없으면 디폴트 키 세팅을, 있으면 커스텀 한 키세팅을 불러와 KeyConfig테이블 구성
         - SaveUserKeySetting() = 커스텀 한 키세팅을 저장하기 위한 함수
         - SendServer() = 키 세팅을 데이터 스토리지로 보내기 위한 함수(SERVER)

    2. KeyConfigScript
         - 디폴트 키 세팅과 아이콘들의 실행 함수(event)를 담은 Script
         - nil슬롯에 저장되는 키 세팅 테이블(마우스 우클릭 시 아이콘들이 nil슬롯들로 이동하는 데 이를 구현하기 위한 테이블)

    3. KeyIconCmponent
     - DragButtonComponent를 확장한 Component   
     - 스킬 아이콘으로서 작동하기 위한 Component   
     - OnInitialize함수를 이용하여 자신의 이름을 추출한다.
         > 키세팅을 변경할 때 마다(부모 entity인 슬롯이 변경될 때 마다)
         > 부모entity.SlotComponent에 자신의 이름을 저장한다.
     - 초기화 기능과, default키세팅으로 되돌리기 기능 추가
     - grab시
         > 자신의 이름을 키세팅UI에서 있는 KeyConfigComponent에 저장한다   
         > DragButtonComponent가 작동되고, RaycastTarget이 비활성화된다.   
         > grab한 상태에서 슬롯이 호버 되면 행당 슬롯에 자신의 이름이 저장된다
         > (RaycastTarget이 비활성화 되고, 놓으면 활성화 된다.)
 
    4. SlotComponent
        - 슬롯으로서 작동을 구현한 Component   
        issue   
        - 키 입력을 하면 모든 슬롯들이 호출됨(85개의 슬롯들이 한꺼번에 키다운, 키 릴리즈 이벤트를 실행함)
        - 비활성화 되면 자식 슬롯들 중 키가 없는 것들도 비활성화 되게끔 구현하면 되겠네   
            onupdate함수를 쓰면 쉽게 구현 가능 but 프레임 드랍이 심해짐, closeButton 클릭 시 이벤트가 전달 되도록 구현하면 좋을 듯

    5. KeyConfigComponent
        - 아이콘과 슬롯이 원활하게 작동하기 위해 필요한 Component
        - KeyConfigUI에 붙어있음
        - 비활성화 되면 자식 슬롯들 중 키가 없는 것들도 비활성화 되게끔 구현하면 되겠네
            onupdate함수를 쓰면 쉽게 구현 가능 but 프레임 드랍이 심해짐, closeButton 클릭 시 이벤트가 전달 되도록 구현하면 좋을 듯