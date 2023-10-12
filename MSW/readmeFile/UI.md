 # UI(2023-05-17 13:00)

**UI관련 컴포넌트, 로직, 스크립트, 데이터셋에 관련된 readme파일입니다.**   

    - UIButton
        - _UIButtonComponent   
            기본 버튼 컴포넌트를 확장한 컴포넌트(ver.핀)   
            
        - DragButton   
            드래그 기능을 구현한 컴포넌트(ver.핀)   

        - CloseButton   
            닫기 기능을 구현한 컴포넌트(ver.핀)
            > 버튼 클릭 시 CustomUILogic에 있는 테이블에 해당 entity를 저장하여   
            > esc키 입력 시 enable한 순서대로 창이 닫히도록 구현하였다. 
        - DetailButton
            StatUI에 있는 디테일 버튼을 구현하기 위한 컴포넌트

        - NewMouseClick   
            해당 컴포넌트를 포함한 버튼이 마우스 오버 시 Curse가 클릭 스프라이트로 바뀐다.
       
        - NewMouseItem   
            해당 컴포넌트를 포함한 버튼이 마우스 오버 시 Curse가 Item 스프라이트로 바뀐다.
        
        - NewMouseScroll   
            해당 컴포넌트를 포함한 버튼이 마우스 오버 시 Curse가 스크롤 스프라이트로 바뀐다.
        
        - StatusUIButtonComponent   
            StatusUIButton들을 구현한 컴포넌트
            각각의 이름을 추출해 버튼 클릭 시 해당 이름에 해당하는 UI를 enable한다.
            >버튼 클릭 시 CustomUILogic에 있는 테이블에 해당 entity를 저장하여   
            >esc키 입력 시 enable한 순서대로 창이 닫히도록 구현하였다.  
            
    - UILayerComponent
        ui를 클릭 시 해당 ui가 앞으로 오게 하는 컴포넌트   
        ui그룹을 이동하는 방식으로 구현하였다.   
        - issue   
            - subUI들 고려해야 함.

    - CustomUILogic
        - UI창을 열고 닫을 때 닫는 순서를 정하기 위한 테이블이 구현되어 있다.   
          UI를 열 때마다 테이블에 해당 엔티티를 저장하고,   
          해당 UI컴포넌트에 테이블의 자신의 위치를 기억하도록 한다.   
          esc키를 입력할 때마다 table.remove()를 이용하여 역순으로 UI를 닫는다.   
          만약 CloseButton을 클릭 닫는다면 정확하게 실행할 필요가 있다.   
          table.remove()는 마지막 값만 삭제하기 때문에 테이블에서 제거되는 value와 닫은 ui가 다를 수 있다.
          때문에 CloseButton의 부모 엔티티에 있는 키값(순서)을 이용하여 테이블에서 정확한 value를 제거한다.
        - SetStat() : 플레이어의 스텟을 출력하는 함수   
        - issue
            간혹 esc키를 눌러도 작동하지 않는 경우가 있는 데 UI를 닫는 방법이 여러가지가 있어
            테이블 삭제 및 테이블 정렬이 제대로 되지 않아 발생하는 문제인 것 같다.