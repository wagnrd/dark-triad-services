-- Delete all characters --
delete
from character;

-- Fetch all characters --
select character.*,
       appearance.*,
       equipment.*,
       statistic.last_used_timestamp
from character,
     appearance,
     equipment,
     statistic
where character.name = appearance.character
  and character.name = equipment.character
  and character.name = statistic.character;