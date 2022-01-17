-- Drop table

-- DROP TABLE public."character";

CREATE TABLE public."character"
(
    user_id text            NOT NULL,
    "name"  varchar(50)     NOT NULL,
    "class" character_class NOT NULL,
    "exp"   int8 NULL DEFAULT 0,
    CONSTRAINT character_pk PRIMARY KEY (name)
);