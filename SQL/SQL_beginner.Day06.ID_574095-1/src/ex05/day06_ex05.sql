COMMENT ON TABLE person_discounts IS 'Таблица содержащая информацию о персональных скидках клиентов';
COMMENT ON COLUMN person_discounts.id IS 'Уникальный идентификатор каждой скидки клиента';
COMMENT ON COLUMN person_discounts.person_id IS 'Уникальный идентификатор каждого клиента';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Уникальный идентификатор каждой пицеррииЮ в котрой действует скидка клиента';
COMMENT ON COLUMN person_discounts.discount IS 'Скидка клиента';