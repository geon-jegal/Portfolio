--[[
���ݹ��� �ȿ� �ǰ��ڰ� �ִٸ� ���� ����(Ÿ��, ������, �����̻� ��)�� �ǰ� �Լ��� �Ű� ������ �ڵ����� �Ѱ��ش�.

Attack
- ����: ����(�浹) �׷�, ���� ����, ������, �ǰ���, ���� ����(���ڿ� ����, ex) Ÿ��, �����̻�, ũȮ, ��ų ȿ��, �Ӽ�, ���߷�)
-- ���� ������ ���ڿ��� ���̺��� �ٲپ� ���(TableToString, StringToTable)
-- �� ���� ������ ���Ӹ��� �ٸ��Ƿ� ������Ʈ�� ������Ƽ�� �ƴ� �������̵� ������Ʈ, �Լ����� ���� ���
- �Լ�
- Attack(): ���� ���� ���� �Լ�, ���� ��������
- CalcCritical(): ũ��Ƽ�� ���� ����, ũȮ ����, �������̵� ����
- CalcDamage(): ������ ��� �Լ�, �������̵� ����
- GetCriticalDamageRate(): ũ�� ��� �Լ�, �������̵� ����
- GetDisplayHitCount(): Ÿ�� ��� �Լ�, �������̵� ����
- IsAttackTarget(): ���� ���� ��� �Լ�(����ġ�� ���� ��� �� ����Ȯ�� ��), �������̵� ����
- OnAttack(): ���� �� ȣ�� �Լ�, AttackEvent �߻�, ���� �� �ڽſ��� ����Ǵ� �͵��� �����ϴ� �Լ�

----------------------------------------------------------------------------------------------------------------

HIT
- ����: �ǰ�(�浹) ����, �ǰ�(�浹) �׷�, ������
- �Լ�
- IsHitTarget(): �ڽ��� �ǰ� ������� Ȯ��, ȸ����, ������ ���� ������ ���� �ϴ��� �ǰ��� ���� �ʴ� ��츦 ��� �ϴ� �Լ�
- OnHit(): �ǰ� �� ȣ��, HitEvent �߻�, �ǰ� �� �ڽſ��� ����Ǵ� �͵��� �����ϴ� �Լ�

]]