import React from 'react';

const DietPlanDisplay = ({ dietPlan }) => {
  let plan;

  try {
    plan = typeof dietPlan === 'string' ? JSON.parse(dietPlan) : dietPlan;

    if (typeof plan !== 'object' || plan === null) {
      throw new Error("Diet plan is not in the expected format.");
    }
  } catch (error) {
    console.error("Error parsing diet plan:", error);
    return <div>Error loading diet plan.</div>;
  }

  return (
    <div className="container">
      <h2>Your Diet Plan</h2>
      <div className="row">
        {Object.entries(plan).map(([day, meals], index) => (
          <div className="col-md-4 mb-4" key={index}>
            <div className="card">
              <div className="card-header">
                <h5>{day}</h5>
              </div>
              <div className="card-body">
                <h6>Breakfast:</h6>
                <ul>
                  {meals.Breakfast.map((item, idx) => (
                    <li key={idx}>{item}</li>
                  ))}
                </ul>
                <h6>Lunch:</h6>
                <ul>
                  {meals.Lunch.map((item, idx) => (
                    <li key={idx}>{item}</li>
                  ))}
                </ul>
                <h6>Dinner:</h6>
                <ul>
                  {meals.Dinner.map((item, idx) => (
                    <li key={idx}>{item}</li>
                  ))}
                </ul>
              </div>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
};

export default DietPlanDisplay;
