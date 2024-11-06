#!/usr/bin/env python
# coding: utf-8

# In[15]:


import pandas as pd
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans


# In[16]:


# Load the dataset with a specific encoding
data = pd.read_csv('sales_data_sample.csv', encoding='ISO-8859-1')  # or 'Windows-1252'

# Display the first few rows of the dataset
print(data.head())


# In[17]:


# Check for missing values
print(data.isnull().sum())

# Optionally, drop rows with missing values (if any)
data.dropna(inplace=True)

# Select relevant features for clustering
features = data[['QUANTITYORDERED', 'SALES']]  # Replace 'Feature1' and 'Feature2' with actual column names


# In[18]:


scaler = StandardScaler()
scaled_features = scaler.fit_transform(features)


# In[19]:


# List to hold the within-cluster sum of squares (WCSS) for each k
wcss = []

# Try different values for k (number of clusters)
for k in range(1, 11):  # Testing k from 1 to 10
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(scaled_features)
    wcss.append(kmeans.inertia_)  # Inertia is the WCSS

# Plot the elbow curve
plt.figure(figsize=(10, 6))
plt.plot(range(1, 11), wcss, marker='o')
plt.title('Elbow Method For Optimal k')
plt.xlabel('Number of clusters (k)')
plt.ylabel('WCSS')
plt.xticks(range(1, 11))
plt.grid()
plt.show()


# In[20]:


# Assuming you found the optimal k to be, for example, 4
optimal_k = 3

kmeans = KMeans(n_clusters=optimal_k, random_state=42)
clusters = kmeans.fit_predict(scaled_features)

# Add cluster labels to the original dataset
data['Cluster'] = clusters

# Display the first few rows with cluster labels
print(data.head())


# In[21]:


plt.figure(figsize=(10, 6))
plt.scatter(scaled_features[:, 0], scaled_features[:, 1], c=clusters, cmap='viridis', marker='o')
plt.title('K-Means Clustering Results')
plt.xlabel('QUANTITYORDERED')
plt.ylabel('SALES')
plt.colorbar(label='Cluster')
plt.show()


# In[23]:


from sklearn.cluster import AgglomerativeClustering
import scipy.cluster.hierarchy as sch

# Create a dendrogram to visualize hierarchical clustering
plt.figure(figsize=(10, 6))
dendrogram = sch.dendrogram(sch.linkage(scaled_features, method='ward'))
plt.title('Dendrogram')
plt.xlabel('QUANTITYORDERED')
plt.ylabel('SALES')
plt.show()

# Apply hierarchical clustering with a specific number of clusters
hc = AgglomerativeClustering(n_clusters=optimal_k)
hc_clusters = hc.fit_predict(scaled_features)

# Add hierarchical cluster labels to the dataset
data['HC_Cluster'] = hc_clusters

# Display the first few rows with hierarchical cluster labels
print(data.head())


# In[ ]:




