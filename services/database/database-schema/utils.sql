-- Delete all characters --
delete
from character;

-- Fetch all characters --
select *
from character,
     appearance,
     equipment
where character.name = appearance.character
  and character.name = equipment.character;