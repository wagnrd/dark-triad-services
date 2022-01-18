-- Drop table

-- DROP TABLE public.appearance;

CREATE TABLE public.appearance
(
    "character"    text NOT NULL,
    gender         text NOT NULL,
    height         text NOT NULL,
    face_id        text NOT NULL,
    eyebrows_id    text NOT NULL,
    ears_id        text NOT NULL,
    hair_id        text NOT NULL,
    facial_hair_id text NOT NULL,
    skin_color     int4 NOT NULL,
    eye_color      int4 NOT NULL,
    scar_color     int4 NOT NULL,
    tattoo_color   int4 NOT NULL,
    hair_color     int4 NOT NULL,
    CONSTRAINT appearance_pk PRIMARY KEY ("character"),
    CONSTRAINT appearance_fk FOREIGN KEY ("character") REFERENCES public."character" ("name") ON DELETE CASCADE
);