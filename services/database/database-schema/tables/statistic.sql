-- public.statistic definition

-- Drop table

-- DROP TABLE public.statistic;

CREATE TABLE public.statistic
(
    "character"         text NOT NULL,
    created_timestamp   int8 NOT NULL,
    last_used_timestamp int8 NOT NULL,
    CONSTRAINT statistic_pk PRIMARY KEY ("character"),
    CONSTRAINT statistic_fk FOREIGN KEY ("character") REFERENCES public."character" ("name") ON DELETE CASCADE ON UPDATE CASCADE
);