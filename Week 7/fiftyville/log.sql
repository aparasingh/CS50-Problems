-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check crime scene report for the day
SELECT * FROM crime_scene_reports where year = 2024 and month = 7 and day = 28;

-- Check interviews for the day
select * from interviews where year = 2024 and month = 7 and day = 28;

-- Check security logs because thief left bakery around 10:15 am
select p.name, p.passport_number, p.phone_number, b.* from bakery_security_logs b join people p ON (p.license_plate = b.license_plate) where b.year = 2024 and b.month = 7 and b.day = 28 and p.passport_number not null and p.phone_number not null;

-- atm transactions at Leggett street based on interviews
select p.name, p.passport_number, p.phone_number, b.* from atm_transactions b join bank_accounts a on (b.account_number=a.account_number) join people p ON (p.id = a.person_id) where b.atm_location="Leggett Street" and b.year = 2024 and b.month = 7 and b.day = 28;

-- phone call around 10:15 am based on interviews
select c.name as caller, r.name as receiver, p.duration from phone_calls p join people c on (c.phone_number= p.caller) join people r on (p.receiver = r.phone_number) where p.year = 2024 and p.month = 7 and p.day = 28;

-- Flights for next day based on interviews
select c.name as culprit, c.passport_number, a.full_name, a.city, f.hour, f.minute from flights f join passengers p on (f.id=p.flight_id) join people c on (c.passport_number= p.passport_number) join airports a on (f.destination_airport_id = a.id) join airports o on (f.origin_airport_id = o.id) where f.year = 2024 and f.month = 7 and f.day = 29 and o.city="Fiftyville";
