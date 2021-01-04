-- Database Name: trms_db
-- Database Name Abbreviation Long Form: Task Reminder Management System (TRMS) Database (DB)

-- Creating Table 1 - AccountStatus
CREATE TABLE AccountStatus(
  AccountStatusID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  AccountStatus VARCHAR(8) NOT NULL
);

-- Inserting records INTO Table 1 - AccountStatus
INSERT INTO AccountStatus(AccountStatus)
VALUES
("Active"),
("Disabled");


-- Creating Table 2 - Login
CREATE TABLE Login(
  LoginID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  EmailAddress VARCHAR(100) NOT NULL UNIQUE,
  PasswordHash VARCHAR(150) NOT NULL,
  asAccountStatusID INTEGER NOT NULL,
  FOREIGN KEY (asAccountStatusID) REFERENCES AccountStatus(AccountStatusID)
);

-- Inserting records INTO Table 2 - Login
INSERT INTO Login(EmailAddress, PasswordHash, asAccountStatusID)
VALUES
("mchatte@gmail.com", "8944854914295023676", 1), -- Password: ChattEddie3$
("lukieklaus@outlook.com", "12919050737726948275", 1), -- Passoword: KlausWest5#
("harlowbillie@gmail.com", "4821787964794285019", 1); -- Password: HarlowHart$2


-- Creating Table 3 - AccountType
CREATE TABLE AccountType(
	AccountTypeID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  AccountType VARCHAR(19) NOT NULL
);

-- Inserting records INTO Table 3 - AccountType
INSERT INTO AccountType(AccountType)
VALUES
("Standard User Account"),
("Premium User Account"),
("AdminAccount");


-- Creating Table 4 - NamePrefix
CREATE TABLE NamePrefix(
	NamePrefixID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  NamePrefix VARCHAR(10) NOT NULL
);

-- Inserting records INTO Table 4 - NamePrefix
INSERT INTO NamePrefix(NamePrefix)
VALUES
("Sir."),
("Mr."),
("Miss."),
("Ms."),
("Mrs."),
("Dr.");


-- Creating Table 5 - BooleanValue
CREATE TABLE BooleanValue(
	BooleanValueID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  BooleanValue BOOLEAN NOT NULL
);

-- Inserting records INTO Table 5 - BooleanValue
INSERT INTO BooleanValue(BooleanValue)
VALUES
(true),
(false);


-- Creating Table 6 - Account
CREATE TABLE Account(
	AccountID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  FirstName VARCHAR(40) NOT NULL,
  MiddleName VARCHAR(40),
  LastName VARCHAR(50) NOT NULL,
  CreatedDateTime DATETIME NOT NULL,
  npNamePrefixID INTEGER NOT NULL,
  atAccountTypeID INTEGER NOT NULL,
  dvDoNotDistrubBooleanValueID INTEGER NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (npNamePrefixID) REFERENCES NamePrefix(NamePrefixID),
  FOREIGN KEY (atAccountTypeID) REFERENCES AccountType(AccountTypeID),
  FOREIGN KEY (dvDoNotDistrubBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 6 - Account
INSERT INTO Account(FirstName, MiddleName, LastName, CreatedDateTime, npNamePrefixID, atAccountTypeID, dvDoNotDistrubBooleanValueID, lLoginID)
VALUES
("Eddie", "Mellicent", "Chatt", "2020-12-26 07:23:28", 2, 1, 2, 1),
("Westley", "Klaus", "Mclukie", "2020-12-27 10:15:28", 2, 2, 2, 2),
("Billie", "Hartwell", "Harlow", "2020-12-28 13:32:28", 2, 3, 2, 3);


-- Creating Table 7 - AccountActivity
CREATE TABLE AccountActivity(
  AccountActivityID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  AccountActivity VARCHAR(7) NOT NULL
);

-- Inserting records INTO Table 7 - AccountActivity
INSERT INTO AccountActivity(AccountActivity)
VALUES
("Online"),
("Offline");


-- Creating Table 8 - LoginActivity
CREATE TABLE LoginActivity(
	LoginActivityID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  LoginDateTime DATETIME NOT NULL,
  LogoutDateTime DATETIME,
  OperatingSystemSpec VARCHAR(50) NOT NULL,
  aaAccountActivityID INTEGER NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 8 - LoginActivity
INSERT INTO LoginActivity(LoginDateTime, LogoutDateTime, OperatingSystemSpec, aaAccountActivityID, lLoginID)
VALUES
("2020-12-28 12:55:28", "2020-12-28 13:55:28", "-", 2, 1);


-- Creating Table 9 - ForgotPassword
CREATE TABLE ForgotPassword(
	RecoveryID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  PinCode VARCHAR(6) NOT NULL,
  NoOfTimesUsed INTEGER NOT NULL,
  CreatedDateTime DATETIME NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 9 - ForgotPassword
INSERT INTO ForgotPassword(PinCode, NoOfTimesUsed, CreatedDateTime, lLoginID)
VALUES
("526871", 1, "2020-12-28 19:55:28", 1);


-- Creating Table 10 - CategoryColour
CREATE TABLE CategoryColour(
	ColourID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  HexColourCode VARCHAR(7) NOT NULL
);

-- Inserting records INTO Table 10 - CategoryColour
INSERT INTO CategoryColour(HexColourCode)
VALUES
("#0C99E4");


-- Creating Table 11 - CategoryType
CREATE TABLE CategoryType(
  CategoryTypeID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  CategoryType VARCHAR(10) NOT NULL
);

-- Inserting records INTO Table 11 - CategoryType
INSERT INTO CategoryType(CategoryType)
VALUES
("Category 1"),
("Category 2"),
("Category 3"),
("Category 4");


-- Creating Table 12 - Category
CREATE TABLE Category(
	CategoryID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  CategoryName VARCHAR(50) NOT NULL,
  ctCategoryTypeID INTEGER NOT NULL,
  ccColourID INTEGER NOT NULL,
  aAccountID INTEGER NOT NULL,
  FOREIGN KEY (ctCategoryTypeID) REFERENCES CategoryType(CategoryTypeID),
  FOREIGN KEY (ccColourID) REFERENCES CategoryColour(ColourID),
  FOREIGN KEY (aAccountID) REFERENCES Account(AccountID)
);

-- Inserting records INTO Table 12 - Category
INSERT INTO Category(CategoryName, ctCategoryTypeID, ccColourID, aAccountID)
VALUES
("Work", 1, 1, 1),
("School", 2, 1, 1),
("Home", 3, 1, 1),
("Category 4", 4, 1, 1),
("School", 1, 1, 2),
("Home", 2, 1, 2),
("Category 3", 3, 1, 2),
("Category 4", 4, 1, 2);


-- Creating Table 13 - Task
CREATE TABLE Task(
	TaskID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  Title VARCHAR(50) NOT NULL,
  TaskDescription VARCHAR(100) NOT NULL,
  StartDateTime DATETIME,
  EndDateTime DATETIME,
  CreatedDateTime DATETIME NOT NULL,
  TerminationDateTime DATETIME,
  LastEditDateTime DATETIME NOT NULL,
  bvImportantBooleanValueID INTEGER,
  aAccountID INTEGER NOT NULL,
  cCategoryID INTEGER NOT NULL,
  FOREIGN KEY (bvImportantBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
  FOREIGN KEY (aAccountID) REFERENCES Account(AccountID),
  FOREIGN KEY (cCategoryID) REFERENCES Category(CategoryID)
);

-- Inserting records INTO Table 13 - Task
INSERT INTO Task(Title, TaskDescription, StartDateTime, EndDateTime, CreatedDateTime, LastEditDateTime, bvImportantBooleanValueID, aAccountID, cCategoryID)
VALUES
("Prepare Document", "Research on Big Analysis and prepare an analysis report", "2020-12-26 09:55:28", "2020-12-26 16:55:28", "2020-12-25 08:55:28", "2020-12-25 08:55:28",  1, 1, 1),
("Analyze Data", "Data analysis of collected data", "2020-12-28 10:55:28", "2020-12-28 12:55:28", "2020-12-27 08:55:28", "2020-12-27 08:55:28", 2, 1, 1);



-- MODIFICATION TO EXISTING TABLE: Altering Table 12 - Category to add new column named 'tPinnedTaskID' and assigning it as a foreign key
ALTER TABLE Category
ADD COLUMN tPinnedTaskID INTEGEREGER
REFERENCES Task(TaskID);

-- MODIFICATION TO EXISTING TABLE: Updating the records after altering Table 12 - Category with a new foreign key
UPDATE Category
SET tPinnedTaskID = 1
WHERE CategoryID = 1;



-- Creating Table 14 - SnoozeDuration
CREATE TABLE SnoozeDuration(
	SnoozeDurationID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  SnoozeDuration VARCHAR(2) NOT NULL
);

-- Inserting records INTO Table 14 - SnoozeDuration
INSERT INTO SnoozeDuration(SnoozeDuration)
VALUES
("1"),
("5"),
("10"),
("15"),
("20"),
("30");


-- Create Table 15 - NoOfSnoozes
CREATE TABLE NoOfSnoozes(
	NoOfSnoozesID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  NoOfSnoozes VARCHAR(2) NOT NULL
);

-- Inserting records INTO Table 15 - NoOfSnoozes
INSERT INTO NoOfSnoozes(NoOfSnoozes)
VALUES
("1"),
("3"),
("5"),
("10");


-- Creating Table 16 - RepeatOccasion
CREATE TABLE RepeatOccasion(
	RepeatOccasionID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  RepeatOccasion VARCHAR(15) NOT NULL
);

-- Inserting records INTO Table 16 - RepeatOccasion
INSERT INTO RepeatOccasion(RepeatOccasion)
VALUES
("Does not repeat"),
("Daily"),
("Weekly"),
("Monthly"),
("Yearly");


-- Creating Table 17 - Reminder
CREATE TABLE Reminder(
	ReminderID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  ReminderDateTime DATETIME NOT NULL,
  sdSnoozeDurationID INTEGER,
  nosNoOfSnoozesID INTEGER,
  rdRepeatOccasionID INTEGER,
  tTaskID INTEGER NOT NULL,
  FOREIGN KEY (sdSnoozeDurationID) REFERENCES SnoozeDuration(SnoozeDurationID),
  FOREIGN KEY (nosNoOfSnoozesID) REFERENCES NoOfSnoozes(NoOfSnoozesID),
  FOREIGN KEY (rdRepeatOccasionID) REFERENCES RepeatOccasion(RepeatOccasionID),
  FOREIGN KEY (tTaskID) REFERENCES Task(TaskID)
);

-- Inserting records INTO Table 17 - Reminder
INSERT INTO Reminder(ReminderDateTime, tTaskID)
VALUES
("2020-12-26 08:55:28", 1);
INSERT INTO Reminder(ReminderDateTime, sdSnoozeDurationID, nosNoOfSnoozesID, rdRepeatOccasionID, tTaskID)
VALUES
("2020-12-28 09:55:28", 2, 2, 1, 2);


-- Creating Table 18 - ReviewStatus
CREATE TABLE ReviewStatus(
  ReviewStatusID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  ReviewStatus VARCHAR(15) NOT NULL
);

-- Inserting records INTO Table 18 - ReviewStatusID
INSERT INTO ReviewStatus(ReviewStatus)
VALUES
("Review Pending"),
("Review Complete");

-- Creating Table 19 - Report
CREATE TABLE Report(
	ReportID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  ReportSubject VARCHAR(50) NOT NULL,
  Feedback VARCHAR(150) NOT NULL,
  SubmittedDateTime DATETIME NOT NULL,
  AuthorReachableEmailAddress VARCHAR(100),
  rsReviewStatusID INTEGER DEFAULT 1,
  aAccountID INTEGER,
  FOREIGN KEY (aAccountID) REFERENCES Account(AccountID),
  FOREIGN KEY (rsReviewStatusID) REFERENCES ReviewStatus(ReviewStatusID)
);

-- Inserting records INTO Table 19 - Report
INSERT INTO Report(ReportSubject, Feedback, SubmittedDateTime, rsReviewStatusID, aAccountID)
VALUES
("Application is Working Well", "This task reminder application is working incredibly well.", "2020-12-27 05:55:28", 1, 1),
("Login Not Working", "There was an issue with my login", "2020-12-28 05:55:28", 2, 1);
