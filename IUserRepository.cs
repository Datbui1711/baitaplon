using System;
using KoiShowManagementSystem.Repositories.Entities;

namespace KoiShowManagementSystem.Repositories.Interface
{
	public interface IUserRepository
	{
		Task<List<User>> GetAllUse();
        Boolean DelUser(int Id);
        Boolean DelUser(User user);
        Boolean AddUser(User user);
        Boolean UpdtUser(User user);
        Task<User> GetUserById(int Id);
    }
}

