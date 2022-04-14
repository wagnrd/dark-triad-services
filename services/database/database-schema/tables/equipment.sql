-- public.equipment definition

-- Drop table

-- DROP TABLE public.equipment;

CREATE TABLE public.equipment
(
    "character"     text NOT NULL,
    main_weapon     text NOT NULL,
    support_weapon  text NOT NULL,
    head_armour     text NOT NULL,
    torso_armour    text NOT NULL,
    shoulder_armour text NOT NULL,
    arm_armour      text NOT NULL,
    leg_armour      text NOT NULL,
    foot_armour     text NOT NULL,
    CONSTRAINT equipment_pk PRIMARY KEY ("character"),
    CONSTRAINT equipment_fk FOREIGN KEY ("character") REFERENCES public."character" ("name") ON DELETE CASCADE ON UPDATE CASCADE
);