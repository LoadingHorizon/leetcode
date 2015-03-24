-- Combine Two Tables

-- Person left join Address 1070ms
SELECT Firstname, LastName, City, State
FROM Person LEFT OUTER JOIN Address
ON Person.PersonId = Address.PersonId;

-- Address right join Person 1222ms
SELECT Firstname, LastName, City, State
FROM Address RIGHT OUTER JOIN Person
ON Person.PersonId = Address.PersonId;
