 # MapleChronicle(2023-10-13 11:20) 

### About<hr/>
DPM폴더
3년전 군 입대전 C++을 연습할 겸 잠깐 만들어 본 것입니다.
당연히 프로그래밍을 막 시작한 시절에 만든 것이라 많이 부족한 부분이 있습니다.
(2023-05-09 14:00)
   

MSW폴더
기본적인 그룹은 컴포넌트는 컴포넌트끼리, 로직은 로직끼리 데이터셋은 데이터셋끼리 즉, API끼리 분류한다.   
하지만 설명의 용이성을 위해 하나의 기능으로 작동하는 api들은 묶어서 설명한다.   
(사실 제가 이해하기 편한 방식으로 작성한 것입니다.추후 개발자들끼리 논의 후 수정한다.)   

- 전체적인 코드를 개선하여 용량을 줄여야 한다.
    - 기본 코드가 13mb.... 심지어 아직 덜 구현한 것
    - 메인 퀘스트와 같은 전체적인 볼륨이 다 들어가면 100mb는 될 듯
    - 메월드에서 제공하는 api들중 재활용 할 수 있는 것들은 최대한 재활용한다.(개인적으로 폰트와 타일, 뒤배경....)

아레의 설명들은 구현이 덜 되었거나, 삭제 예정(임시 구현) 또는 분류하기 애매해서 이곳에 기술하였습니다.(추후 수정)   
- 마우스 커서
    1. Mouse.MODPACKAGE 사용
    2. 기존 마우스를 안 보이게 하고 마우스 엔티티를 덮어씌어 구현
    3. ui엔티티에 ButtonComponent와 자체 제작한 Component를 추가하여 버튼 홀드 시 마우스 엔티티의 상태를 변경   
    issue
     - 게임 종료 버튼이 가장 바깥 레이어로 되어있어 버튼 클릭 시 마우스 이미지위로 종료 레이어가 생긴다.
     - 메월드에서 제공하는 기본 기능들에 한해서는 마우스 커서가 해당 기능들 밑으로 들어가게 되어 커서 사용 불가.

- 메인 인터페이스

- 몬스터
    각각의 몬스터들은 Model이 있다.   

- 플레이어
    
- 포탈
    - 플레이어가 포탈 사용 시 페이드 인, 아웃이 작동된다.   
    - 기본 모델이 있으므로 해당 모델을 사용한다.   
    - 히든 포탈은 추가 제작이 필요.   

- fade in, out
    - _UIFadeComponent   
    - rpg_base에 있는 컴포넌트   

- 카메라
    - PerspectiveComponent: Mundo님이 만드신 컴포넌트, 배경 object에 사용되는 컴포넌트로   
    각각의 배경 object마다 카메라의 움직임에 비례한 움직임이 다르게 한다.(각 object들과 플레이어의 거리가 달라서 생기는 현상)
    이를 구현하기 위한 컴포넌트.
    프로퍼티 값에 따라 카메라가 움직임에 따른 배경 object의 움직임이 달라진다.

- etc   
    NPC, monster, 리액터(보물상자, 포탈, 함정), 아이템, baseUI들은 모델을 만들어 둔다.   
    Component, Logic, AI, Sprict, Event, State 관련 정리하기, 나만의 시작가이드와 API레퍼런스 만들기   
    <https://maplestoryworlds-developers.nexon.com/ko/docs/?postId=723>,   
    <https://maplestoryworlds-developers.nexon.com/ko/apiReference/How-to-use-API-Reference> 참고   
    <https://www.notion.so/publisher-kr/2323989fd4e14e0fbf734a6e5c4f0648> 노션-개발 링크

 - 시연 영상   
    <https://youtu.be/bS2iVpto_50>   
    <https://youtu.be/KDjH_HYtR6U>   