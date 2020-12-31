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
Values ("mchatte@toplist.cz", "8944854914295023676", 1); -- Password: ChattEddie3$


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


-- Creating Table 4 - BooleanValue
CREATE TABLE BooleanValue(
	BooleanValueID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  BooleanValue BOOLEAN NOT NULL
);

-- Inserting records INTO Table 4 - BooleanValue
INSERT INTO BooleanValue(BooleanValue)
VALUES
(true),
(false);


-- Creating Table 5 - Account
CREATE TABLE Account(
	AccountID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  FirstName VARCHAR(40) NOT NULL,
  MiddleName VARCHAR(40),
  LastName VARCHAR(50) NOT NULL,
  CreatedDateTime DATETIME DEFAULT CURRENT_TIMESTAMP,
  atAccountTypeID INTEGER NOT NULL,
  dvDoNotDistrubBooleanValueID INTEGER NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (atAccountTypeID) REFERENCES AccountType(AccountTypeID),
  FOREIGN KEY (dvDoNotDistrubBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 5 - Account
INSERT INTO Account(FirstName, MiddleName, LastName, atAccountTypeID, dvDoNotDistrubBooleanValueID, lLoginID)
VALUES
("Eddie", "Mellicent", "Chatt", 1, 2, 1);


-- Creating Table 6 - AccountActivity
CREATE TABLE AccountActivity(
  AccountActivityID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  AccountActivity VARCHAR(7) NOT NULL
);

-- Inserting records INTO Table 6 - AccountActivity
INSERT INTO AccountActivity(AccountActivity)
VALUES
("Online"),
("Offline");


-- Creating Table 7 - LoginActivity
CREATE TABLE LoginActivity(
	LoginActivityID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  LoginDateTime DATETIME NOT NULL,
  LogoutDateTime DATETIME NOT NULL,
  OperatingSystemSpec VARCHAR(50) NOT NULL,
  aaAccountActivityID INTEGER NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 7 - LoginActivity
INSERT INTO LoginActivity(LoginDateTime, LogoutDateTime, OperatingSystemSpec, aaAccountActivityID, lLoginID)
VALUES
("2020-12-28 12:55:28", "2020-12-28 13:55:28", "-", 2, 1);


-- Creating Table 8 - ForgotPassword
CREATE TABLE ForgotPassword(
	RecoveryID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  PinCode VARCHAR(6) NOT NULL,
  NoOfTimesUsed INTEGER NOT NULL,
  CreatedDateTime DATETIME NOT NULL,
  lLoginID INTEGER NOT NULL,
  FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
);

-- Inserting records INTO Table 8 - ForgotPassword
INSERT INTO ForgotPassword(PinCode, NoOfTimesUsed, CreatedDateTime, lLoginID)
VALUES
("526871", 1, "2020-12-28 19:55:28", 1);


-- Creating Table 9 - CategoryColour
CREATE TABLE CategoryColour(
	ColourID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  HexColourCode VARCHAR(7) NOT NULL
);

-- Inserting records INTO Table 9 - CategoryColour
INSERT INTO CategoryColour(HexColourCode)
VALUES
("#0C99E4");


-- Creating Table 10 - Category
CREATE TABLE Category(
	CategoryID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  CategoryName VARCHAR(50) NOT NULL,
  ccColourID INTEGER NOT NULL
);

-- Inserting records INTO Table 10 - Category
INSERT INTO Category(CategoryName, ccColourID)
VALUES
("Work", 1);


-- Creating Table 11 - Task
CREATE TABLE Task(
	TaskID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  Title VARCHAR(50) NOT NULL,
  TaskDescription VARCHAR(100) NOT NULL,
  StartDateTime DATETIME NOT NULL,
  EndDateTime DATETIME NOT NULL,
  CreatedDateTime DATETIME NOT NULL,
  TerminationDateTime DATETIME,
  LastEditDateTime DATETIME NOT NULL,
  bvImportantBooleanValueID INTEGER NOT NULL,
  aAccountID INTEGER NOT NULL,
  cCategoryID INTEGER NOT NULL,
  FOREIGN KEY (bvImportantBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
  FOREIGN KEY (aAccountID) REFERENCES Account(AccountID),
  FOREIGN KEY (cCategoryID) REFERENCES Category(CategoryID)
);

-- Inserting records INTO Table 11 - Task
INSERT INTO Task(Title, TaskDescription, StartDateTime, EndDateTime, CreatedDateTime, LastEditDateTime, bvImportantBooleanValueID, aAccountID, cCategoryID)
VALUES
("Prepare Document", "Research on Big Analysis and prepare an analysis report", "2020-12-26 09:55:28", "2020-12-26 16:55:28", "2020-12-25 08:55:28", "2020-12-25 08:55:28",  1, 1, 1),
("Analyze Data", "Data analysis of collected data", "2020-12-28 10:55:28", "2020-12-28 12:55:28", "2020-12-27 08:55:28", "2020-12-27 08:55:28", 2, 1, 1);


-- MODIFICATION TO EXISTING TABLE: Altering Table 10 - Category to add new column named 'tPinnedTaskID' and assigning it as a foreign key
ALTER TABLE Category
ADD COLUMN tPinnedTaskID INTEGEREGER
REFERENCES Task(TaskID);

-- MODIFICATION TO EXISTING TABLE: Updating the records after altering Table 10 - Category with a new foreign key
UPDATE Category
SET tPinnedTaskID = 1
WHERE CategoryID = 1;


-- Creating Table 12 - SnoozeDuration
CREATE TABLE SnoozeDuration(
	SnoozeDurationID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  SnoozeDuration VARCHAR(2) NOT NULL
);

-- Inserting INTO Table 12 - SnoozeDuration
INSERT INTO SnoozeDuration(SnoozeDuration)
VALUES
("1"),
("5"),
("10"),
("15"),
("20"),
("30");


-- Create Table 13 - NoOfSnoozes
CREATE TABLE NoOfSnoozes(
	NoOfSnoozesID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  NoOfSnoozes VARCHAR(2) NOT NULL
);

-- Inserting INTO Table 13 - NoOfSnoozes
INSERT INTO NoOfSnoozes(NoOfSnoozes)
VALUES
("1"),
("3"),
("5"),
("10");


-- Creating Table 14 - RepeatOccasion
CREATE TABLE RepeatOccasion(
	RepeatOccasionID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  RepeatOccasion VARCHAR(15) NOT NULL
);

-- Inserting INTO Table 14 - RepeatOccasion
INSERT INTO RepeatOccasion(RepeatOccasion)
VALUES
("Does not repeat"),
("Daily"),
("Weekly"),
("Monthly"),
("Yearly");


-- Creating Table 15 - Reminder
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

-- Inserting records INTO Table 15 - Reminder
INSERT INTO Reminder(ReminderDateTime, tTaskID)
VALUES
("2020-12-26 08:55:28", 1);
INSERT INTO Reminder(ReminderDateTime, sdSnoozeDurationID, nosNoOfSnoozesID, rdRepeatOccasionID, tTaskID)
VALUES
("2020-12-28 09:55:28", 2, 2, 1, 2);


-- Creating Table 16 - Report
CREATE TABLE Report(
	ReportID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  ReportSubject VARCHAR(50) NOT NULL,
  Feedback VARCHAR(150) NOT NULL,
  SubmittedDateTime DATETIME NOT NULL,
  aAccountID INTEGER NOT NULL,
  FOREIGN KEY (aAccountID) REFERENCES Account(AccountID)
);

-- Inserting records INTO Table 16 - Report
INSERT INTO Report(ReportSubject, Feedback, SubmittedDateTime, aAccountID)
VALUES
("Application is Working Well", "This task reminder application is working incredibly well.", "2020-12-27 05:55:28", 1);
