import numpy as np
class KMeans:
    def __init__(self,n_clusters,max_iters):#初始化参数,数据，簇的个数,最大迭代次数
        self.n_clusters=n_clusters
        self.max_iters=max_iters
        self.centroids = None  #簇心
        self.labels = None     #记录每个样本所属的簇心
    
    def train(self,data):#训练函数
        #初始化簇心
        n_samples=data.shape[0]
        random_ids=np.random.permutation(n_samples) #生成随机的序列
        self.centroids=data[random_ids[:self.n_clusters]] #通过索引初始化簇心

        for _ in range(self.max_iters):#最多迭代max_iters次
            old_centroids=self.centroids.copy() #更新前保留簇心,用于比较是否变化
            self.assign_clusters(data) #分配数据点到最近的聚类中心
            self.updata_centroids(data) #更新簇心
            if np.array_equal(old_centroids, self.centroids): #如果簇心已经稳定,跳出循环
                break;
        return self

    #预测函数
    def predict(self,data):
        self.assign_clusters(data)
        return self.labels
    
    #分配数据点到最近的聚类中心
    def assign_clusters(self,data):
        n_samples=data.shape[0]  #样本数量
        self.labels=np.zeros(n_samples) #记录每个样本所属的簇心(距离最近）
        for samples_index in range(n_samples):  #分别遍历样本和簇心,计算他们之间的位置
            distance=np.zeros((self.n_clusters,1))
            for clusters_index in range(self.n_clusters):
                distance_curr=data[samples_index,:]-self.centroids[clusters_index,:] #样本和簇心相减
                distance[clusters_index]=np.sum(distance_curr**2)  #欧几里得距离
            self.labels[samples_index]=np.argmin(distance) #分配样本点到最近的簇心

    #更新簇心为每个簇中所有点的平均值
    def updata_centroids(self, data):
        for i in range(self.n_clusters):
            cluster_points = data[self.labels==i]
            if len(cluster_points) > 0:  #如果该簇里有元素，就更新,求簇里所有元素的平均值
                self.centroids[i] = cluster_points.mean(axis=0)

