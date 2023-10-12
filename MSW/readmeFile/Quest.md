 # Quest(2023-05-17 13:00)
   
**Quest관련 컴포넌트, 로직, 스크립트, 데이터셋에 관련된 readme파일입니다.**   

    1. QuestPanelLogic(Logic)
        - 퀘스트 페널을 출력해주는 Logic.(메인, 서브)   
        - 플레이어가 npc키 입력 시 해당 로직이 실행 되며 플레이어 컴포넌트에 있는 퀘스트 정보를 읽어 해당하는 퀘스트(스크립트)를 출력한다.   
        - 해당 로직 작동 시 SetPlayerCtrl(Logic)이 실행되는 데 스크립트 출력 시 플레이어가 움직이지 못하도록 하기위해 실행된다.   
    
    2. QuestComponent(Component)
        - NPC에 붙어 있는 Component로 유저의 퀘스트데이터를 받아와 현재 실행해야 하는 퀘스트 정보를 플레이어 컴포넌트에 보낸다.   

    3. QuestButton(Component)
        - 비슷한 QuestPanelUI(Entity)가 많아 각각의 버튼들이 동일한 기능을 수행할 수 있도록 하는 Component.
       
    4. PanelTable(Script)
        - 퀘스트 페널 Entity의 id를 담고있는 Table
        - 스크립트를 출력할 때 UI를 출력하는 경우가 여러가지이다.   
        - 때문에 모든 경우를 구현한 패널 entity를 구현하였고 이를 테이블에 담았다.   
    
    5. 퀘스트 테이블(Data set)
        - 하나의 퀘스트의 정보를 담고 있는 Data set
    
    6. etc
        - 전체적인 퀘스트 정보는 GlobalDataStorage에 저장하고 각각의 퀘스트는 Data set에 저장
        - QuestComponent에서 UserDataStorage에 있는 유저가 진행중인 퀘스트의 정보를 불러옴 -> 퀘스트 정보에 맞는 QuestPanelLogic을 불러옴 -> 대화 출력 -> 대화 종료 후 UserDataStorage 업데이트

    7. Issue
        - 서브 퀘스트는 핀님이 제작
        - Json파일이 완성되면 전채적인 구조 개편(개선) 필요.   
