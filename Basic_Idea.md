Basic Idea
Online Examination Proctoring Event Analyzer
The basic idea of this project is to monitor activities of a candidate during an examination and identify suspicious behaviour.
The system will not directly declare that a student is cheating. It will record suspicious activities with their time and duration so that they can be reviewed later.
The system can be used for both online and written examinations.
Activities to Monitor

1. Face Detection
   - Face not visible
   - Multiple faces detected
   - Candidate face mismatch

2. Eye and Head Movement
   - Unusual head movement
   - Prolonged gaze outside the permitted region
   - Downward side-eye movement

   Permitted regions can include:
   - Exam screen / question paper
   - Answer sheet

3. Screen Activity
   - Split-screen detection
   - Tab switching
   - Copy activity
   - Paste activity

Basic Flow

Candidate gives exam  
→ Activities are monitored  
→ Suspicious events are detected  
→ Event and timestamp are stored  
→ Events are analyzed  
→ Suspicious patterns are identified  
→ Cases are prioritized for manual review

The project will later use different DAA algorithms to analyze and compare these events efficiently.
