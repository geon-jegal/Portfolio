PlayerDataLogic(2023-10-12 20:20)

  **PlayerDataLogic�� ���� ������ ����� readme�����Դϴ�.**
  �⺻������ KeyConfigLogic�� ������ ���·� �۵��մϴ�.
  SetData(), SaveData()�� Ŭ���̾�Ʈ���� ����ǰ� �������� ���� �������� ����ȴ�.

  - EnterUserData
	- ���ӿ� ������ ������ id�� �޾� �����͸� ��� �´�. 

  - getData
	- ���ڿ��� �Է¹��� �����͸� ���̺�� ��ȯ�Ѵ�

  - SetData
	- ������ Ư�� �����͸� ������ �� ����ϴ� �Լ�
	- ���� ������ level up�� �Ѵٸ� level, ���ݵ��� �����ϴµ� ����Ѵ�
	- ex) _PlayerDataLogic:SetData("MaxExp", self.MaxExp)

  - SaveData
	- ���̺��� ���ڿ��� ��ȯ �� ������ ������.

  - SendServer
	- ���ڿ��� ��ȯ�� �����͸� ������ ������.

  - SetPlayer
	- ���� ���� �� �ٷ� �����ϴ� �Լ��̴�.
	- ������ �����͸� �����Ѵ�.

  - OnBeginPlay
	- ������ ���ʵ����͸� �����Ѵ�.