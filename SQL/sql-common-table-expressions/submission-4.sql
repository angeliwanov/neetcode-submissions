CREATE TABLE customers (
  id INTEGER PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  name TEXT
);

CREATE TABLE orders (
  id INTEGER PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
  customer_id INTEGER,
  price INTEGER
);

INSERT INTO customers (name) VALUES
  ('Alice'),
  ('Bob'),
  ('Charlie'),
  ('David'),
  ('Eve'),
  ('Frank'),
  ('Grace'),
  ('Hank');

INSERT INTO orders (customer_id, price) VALUES
  (1, 50),
  (2, 100),
  (3, 150),
  (4, 200),
  (5, 250),
  (6, 30),
  (7, 70),
  (8, 400);
-- Do not modify above this line. --


WITH lvo AS (
    SELECT customer_id
    FROM orders
    WHERE price < 100
    GROUP BY customer_id
)

SELECT c.name
FROM customers c
JOIN lvo ON lvo.customer_id = c.id
ORDER BY name ASC;










