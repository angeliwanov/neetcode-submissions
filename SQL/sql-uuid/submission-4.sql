CREATE TABLE users (
    id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
    name TEXT
);


/*
INSERT INTO users (name) 
  VALUES ('Alex'),
         ('Jane'),
         ('Bob');
*/



-- Do not modify below this line --
SELECT * FROM users;
