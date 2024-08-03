# Nutrition System Frontend

This repository contains the client-side code for the Nutrition System application, built using React.js and Bootstrap. The application allows users to enter their personal information, request a diet plan, view the generated plan, and provide feedback.

## Components Overview

### 1. `App.js`

The main component that manages the application state and flow. It handles:
- Displaying the `PatientForm` for user input.
- Showing the `DietPlanDisplay` after receiving the diet plan.
- Displaying the `FeedbackForm` for user feedback.

### 2. `PatientForm.js`

A form component that collects user information including:
- Name
- Age
- Gender
- Height
- Weight
- Diseases (comma-separated)

After submitting the form, it sends the data to the server and receives a diet plan along with a user ID.

### 3. `DietPlanDisplay.js`

A component to display the generated diet plan. It renders the plan in a structured format with sections for breakfast, lunch, and dinner for each day.

### 4. `FeedbackForm.js`

A form component that collects feedback from the user after they have reviewed the diet plan. It submits the feedback score to the server.

## Getting Started

To use this code, follow these steps:

### 1. Create a New React App

If you don't have an existing React app, create one using the `create-react-app` tool. Run the following command:

```bash
npx create-react-app my-nutrition-app
